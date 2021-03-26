#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_W 1000

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue <pair <int, int> > fire;

int w, h, testCase;
int bldg[MAX_W][MAX_W];
bool visited[MAX_W][MAX_W];
int initX, initY;

int simulate(int startX, int startY) {
    queue <pair <int, int> > q;
    q.push({startX, startY});
    int result = 1;
    
    while(1) {
        result++;
        int fireSize = fire.size();
        while(fireSize--) {
            int x = fire.front().first;
            int y = fire.front().second;
            fire.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (bldg[nx][ny] == 1 || bldg[nx][ny] == 2) continue;
                bldg[nx][ny] = 1;
                fire.push({nx, ny});
            }
        }
        
        if (q.empty()) return -1;
        int qSize = q.size();
        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (bldg[nx][ny] == 3) return result;
                if (visited[nx][ny] || bldg[nx][ny] == 1 || bldg[nx][ny] == 2) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void init() {
    while(!fire.empty()) fire.pop();
    memset(bldg, 0, sizeof(bldg));
    memset(visited, false, sizeof(visited));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    for (int tc = 0; tc < testCase; tc++) {
        //초기화
        init();
        cin >> w >> h;
        //건물의 상태에 대한 입력을 받는다.
        //탈출 가능한 지점인 경우 'G'로 치환해서 입력을 받고,
        //상근이의 현재 위치의 경우 '.'으로 치환해서 입력을 받음과 동시에 bfs를 위한
        //queue에 push한다.
        bool startEscape = false;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char temp;
                cin >> temp;
                if (temp == '@') {
                    if ((i == 0 || j == 0 || i == (h-1) || j == (w-1)))
                        startEscape = true;
                    temp = '.';
                    initX = i; initY = j;
                }
                else if (temp == '*')
                    fire.push({i, j});
                else if ((i == 0 || j == 0 || i == (h-1) || j == (w-1)) && temp == '.')
                    temp = 'G';
                if (temp == '.') bldg[i][j] = 0;
                if (temp == '*') bldg[i][j] = 1;
                if (temp == '#') bldg[i][j] = 2;
                if (temp == 'G') bldg[i][j] = 3;
            }
        }
        
        if (startEscape) {
            cout << 1 << '\n';
            continue;
        }
        int outcome = simulate(initX, initY);
        
        //결과를 출력한다.
        if (outcome == -1) cout << "IMPOSSIBLE\n";
        else cout << outcome << '\n';
    }
    return 0;
}
