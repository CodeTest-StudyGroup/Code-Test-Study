#define _CRT_SECURE_NO_WARNINGS

#define maxHeight 6
#define setup 10
#define ascend 1
#define descend 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[21][21];
int test[6][21];
int N, X, T;

bool solve(vector<int> path) {

    bool flag = false;
    vector<int> temp;
    vector<pair<int, int> > point;

    // [0] 한 줄 데이터 담아두기
    for (int i = 0; i < N; i++) temp.push_back(path[i]);
    
    // [1] 높이에 따른 그래프 생성 (Fig. 6과 같은)
    for (int i = maxHeight - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (path[j] > 0) {
                test[i][j] = 1;
                path[j] -= 1;
            }
        }
    }

    // [2] 높이가 한 칸 차이나는 곳들의 열번호를 구해놓는다.
    // 이에 더해, 경사로가 왼쪽에서 그 위치까지 올라오는 경사로인지, 그 위치에서 내려가는 경사로인지 판단해 둔다.
    for (int i = 0; i < N - 1; i++) {
        if (temp[i] != temp[i+1]) {
            if (temp[i] < temp[i+1] && ((temp[i+1] - temp[i]) == 1)) {
                point.push_back(make_pair(i, ascend));
            }
            else if (temp[i] > temp[i+1] && ((temp[i] - temp[i+1]) == 1)) {
                point.push_back(make_pair(i+1, descend));
            }
            else if (abs(temp[i+1] - temp[i]) > 1) return false; // 인접한 칸과 한칸 넘는 높이 차이나면 실패
            
        }
    }

    // [3] 구한 열번호를 토대로 경사로(10)를 놓아본다. 단, 이미 놓여 있는 곳에 또 놓으면 오류이다.
    for (int p = 0; p < point.size(); p++) {
        int row = maxHeight - temp[point[p].first] - 1;
        int col = point[p].first;

        // 해당 위치에서 시작하여 오른쪽으로 내려가는 경사로일 때
        if (point[p].second == descend) {
            for (int xi = 0; xi < X; xi++) {            
                if (col >= N) return false; // 올라가는 경사로가 지형 밖까지 나가게 될 경우 false
                if (test[row][col] != setup) test[row][col] = setup;
                else if (test[row][col] == setup) return false;  // 이미 설치되어 있을 경우, 바로 실패 return
                col += 1;
            }
        }

        // 왼편에서부터 해당 위치까지 올라오는 경사로일 때 (= 해당 위치에서 X 길이만큼 왼쪽으로 내려갈 때)
        if (point[p].second == ascend) {
            for (int xi = X; xi > 0; xi--) {
                if (col < 0) return false; // 경사로가 지형 밖까지 나가게 될 경우 false
                if (test[row][col] != setup) test[row][col] = setup;
                else if (test[row][col] == setup) return false; // 이미 설치되어 있을 경우, 바로 실패 return
                col -= 1;
            }
        }
    }

    // [4] test에 놓아진 상황을 토대로, 되지 않는 케이스를 골라낸다.
    for (int i = 0; i < maxHeight; i++) {
        for (int j = 0; j < N; j++) {
            // 설치된 경사로의 면 바로 밑에 또 경사로가 오면 오류이다.
            if (test[i][j] == setup && i + 1 < maxHeight) {
                if (test[i + 1][j] == setup) return false;
            }
        }
    }

    return true;
}

void initial_test() {
    for (int i = maxHeight - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) 
            test[i][j] = 0;       
    }
}

int main() {

    bool flag;
    vector<int> path;
    int OKcnt = 0;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &X);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                scanf("%d", &arr[i][j]);           
        }
        // 가로 방향 살펴보기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) 
                path.push_back(arr[i][j]);

            flag = solve(path);
            if (flag) OKcnt++;
            path.clear();

            initial_test(); // test 배열 초기화
        }

        // 세로 방향 살펴보기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) 
                path.push_back(arr[j][i]);
            
            flag = solve(path);
            if (flag) OKcnt++;
            path.clear();

            initial_test(); // test 배열 초기화
        }

        printf("#%d %d\n", t + 1, OKcnt);
        OKcnt = 0;
    }
    return 0;
}