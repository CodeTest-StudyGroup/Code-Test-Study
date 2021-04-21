#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100

int n, m, r;
pair<int, bool> matrix[MAX_N][MAX_N];
vector <pair <pair <int, int>, char> > attack;
vector <pair <int, int> > defend;
int total_score = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in_boundary(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //입력을 담당하는 부분
    //n, m, r값을 입력받는다.
    cin >> n >> m >> r;
    //초기에 세워진 도미노 각각의 높이를 입력받고, 도미노의 상태 = true로 설정하여 배열에 입력한다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int height;
            cin >> height;
            matrix[i][j] = {height, true};
        }
    }
    //r*2줄에 걸쳐 공격수와 수비수의 행동을 입력 받는다.
    for (int i = 0; i < r; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        attack.push_back({{a-1, b-1}, c});
        cin >> a >> b;
        defend.push_back({a-1, b-1});
    }
    
    //공격 및 수비 시뮬레이션 실행
    for (int round = 0; round < r; round++) {
        int prevX = attack[round].first.first;
        int prevY = attack[round].first.second;
        char move = attack[round].second;
        int pushed = 0;
        int dir;
        switch(move) {
            case 'N':
                dir = 0;
                break;
            case 'S':
                dir = 1;
                break;
            case 'E':
                dir = 2;
                break;
            case 'W':
                dir = 3;
                break;
            default:
                break;
        }
        
        queue <pair <int, int> > q;
        if (matrix[prevX][prevY].second)
            q.push({prevX, prevY});
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int h = matrix[x][y].first;
            for (int l = 0; l < h; l++) {
                int nx = x + (l*dx[dir]);
                int ny = y + (l*dy[dir]);
                if (!in_boundary(nx, ny)) break;
                if (matrix[nx][ny].second) {
                    matrix[nx][ny].second = false;
                    pushed++;
                    q.push({nx, ny});
                }
            }
        }
        
        //수비
        int defX = defend[round].first;
        int defY = defend[round].second;
        matrix[defX][defY].second = true;
        
        //공격자가 넘어뜨린 총 도미노의 개수를 total_score에 갱신한다.
        total_score += pushed;
        
        /*
        //디버깅을 위한 출력
        cout << "round: " << round << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j].second == true)
                    cout << 'S' << " ";
                else cout << 'F' << " ";
            }
            cout << '\n';
        }
        cout << endl;
        */
    }

    //결과 출력을 담당하는 부분
    cout << total_score << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j].second == true)
                cout << 'S' << " ";
            else cout << 'F' << " ";
        }
        cout << '\n';
    }
    return 0;
}
