#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX_N 21

char board[MAX_N][MAX_N];
int m = -1, n = -1;
//0, 2는 가로, 1, 3은 세로
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool is_intersection (char input) {
    if (input - '0' >= 0 && input - '0' <= 9) return true;
    else return false;
}

bool in_boundary (int x, int y) {
    if (x >= 1 && x <= m && y >= 1 && y <= n) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int intersection = -1;
        vector<vector<int>> sectionInfo;
        int ax = -1, ay = -1;
        int bx = -1, by = -1;
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        
        //입력을 받는 부분.
        //숫자를 입력받는 경우, 총 교차로의 갯수를 파악하기 위하여 변수 intersection을 갱신함.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char temp;
                cin >> temp;
                board[i][j] = temp;
                
                if (is_intersection(temp)) {
                    intersection = max(intersection, temp - '0');
                }
                else if (temp == 'A') {
                    ax = i; ay = j;
                }
                else if (temp == 'B') {
                    bx = i; by = j;
                }
            }
        }
        
        //파악한 교차로의 수를 바탕으로 각 교차로에 대한 정보를 입력받음.
        if (intersection != -1) {
            for (int i = 0; i <= intersection; i++) {
                int section_no, eastwest, northsouth;
                char initial_dir;
                cin >> section_no >> initial_dir >> eastwest >> northsouth;
                
                vector<int> roads;
                roads.push_back(-1);    //0번지는 사용하지 않는 값
                if (initial_dir == '-') {
                    for (int j = 0; j < eastwest; j++) {
                        roads.push_back(0); //0은 가로 진입 가능을 의미
                    }
                    for (int j = 0; j < northsouth; j++) {
                        roads.push_back(1); //1은 세로 진입 가능을 의미
                    }
                }
                else {
                    for (int j = 0; j < northsouth; j++) {
                        roads.push_back(1); //1은 세로 진입 가능을 의미
                    }
                    for (int j = 0; j < eastwest; j++) {
                        roads.push_back(0); //0은 가로 진입 가능을 의미
                    }
                }
                sectionInfo.push_back(roads);
            }
        }
        
        //거리 기록 배열 선언 및 초기화
        int d[MAX_N][MAX_N];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = -1;
            }
        }
        
        d[ax][ay] = 0;
        queue<pair<int, int> > q;
        q.push({ax, ay});
        
        while(!q.empty()) {
            int nowX = q.front().first;
            int nowY = q.front().second;
            q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = nowX + dx[dir];
                int ny = nowY + dy[dir];
                
                if (!in_boundary(nx, ny)) continue;
                if (board[nx][ny] == '.') continue;
                
                //교차로가 아닌 경우
                if (!is_intersection(board[nx][ny])) {
                    //진입한 적 없는 곳이거나 값을 새로 갱신해야 하는 경우
                    if (d[nx][ny] == -1 || d[nx][ny] > d[nowX][nowY] + 1) {
                        d[nx][ny] = d[nowX][nowY] + 1;
                        q.push({nx, ny});
                    }
                }
                //교차로인 경우
                else {
                    //진입 방향; 0은 가로 진입, 1은 세로 진입을 의미
                    int enteringDirection = dir % 2;
                    int enteringValue = d[nowX][nowY];
                    int intersectionNo = board[nx][ny] - '0';
                    int intersectionVar = (int)sectionInfo[intersectionNo].size() - 1;
                    
                    while(1) {
                        enteringValue++;
                        int calcValue = enteringValue % intersectionVar;
                        if (calcValue == 0) calcValue = intersectionVar;
                        
                        if (sectionInfo[intersectionNo][calcValue] == enteringDirection) break;
                        
                    }
                    
                    if (d[nx][ny] == -1 || d[nx][ny] > enteringValue) {
                        d[nx][ny] = enteringValue;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        //결과 출력
        if (d[bx][by] == -1) cout << "impossible\n";
        else cout << d[bx][by] << '\n';
    }
    return 0;
}