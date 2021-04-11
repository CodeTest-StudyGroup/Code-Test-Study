#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 50

int n;
char area[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };            //0: 방문 안함, 1: 가로 방문, 2: 세로 방문, 3: 둘 다 방문
vector<pair <int, int> > initialB;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void view_matrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << area[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool in_boundary(int x, int y, int dir) {
    if (dir) {
        int top = x-1; int down = x+1;
        if (x >= 0 && x < n && y >= 0 && y < n && top >= 0 && down < n)
        {
            if (area[top][y] == '1' || area[x][y] == '1' || area[down][y] == '1')
                return false;
            else return true;
        }
    }
    else {
        int left = y-1; int right = y+1;
        if (x >= 0 && x < n && y >= 0 && y < n && left >= 0 && right < n) {
            if (area[x][left] == '1' || area[x][y] == '1' || area[x][right] == '1')
                return false;
            else return true;
        }
    }
    return false;
}

bool is_rotatable(int x, int y) {
    int top = x-1; int down = x+1; int left = y-1; int right = y+1;
    if (top >= 0 && down < n && left >= 0 && right < n) {
        if (area[top][left] != '1' && area[x][left] != '1' && area[down][left] != '1'
            && area[down][y] != '1' && area[down][right] != '1' && area[x][right] != '1'
            && area[top][right] != '1' && area[top][y] != '1')
            return true;
    }
    return false;
}

int bfs(int x, int y, int direction) {
    int result = 1e9;
    queue <pair <pair <int, int>, pair <bool, int> > > q;
    //x(i)좌표, y(j)좌표, 방향, 누적이동수
    q.push({{x,y},{direction,0}});
    if (direction) visited[x][y] = 2;
    else visited[x][y] += 1;
    
    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        bool dir = q.front().second.first;
        int depth = q.front().second.second;
        q.pop();
        
        //디버깅용 코드
        /*
        cout << "i: " << cx << ", j: " << cy << endl;
        cout << "depth: " << depth << endl;
        char debugarray[MAX_N][MAX_N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                debugarray[i][j] = area[i][j];
            }
        }
        if (dir) {
            int top = cx-1; int down = cx+1;
            debugarray[top][cy] = 'B';
            debugarray[cx][cy] = 'B';
            debugarray[down][cy] = 'B';
        }
        else {
            debugarray[cx][cy-1] = 'B';
            debugarray[cx][cy] = 'B';
            debugarray[cx][cy+1] = 'B';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << debugarray[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
         */
         
        
        if (dir) {
            int top = cx-1; int down = cx+1;
            if (area[top][cy] == 'E' && area[cx][cy] == 'E' && area[down][cy] == 'E') {
                result = min(result, depth);
                break;
            }
        }
        else {
            int left = cy-1; int right = cy + 1;
            if (area[cx][left] == 'E' && area[cx][cy] == 'E' && area[cx][right] == 'E') {
                result = min(result, depth);
                break;
            }
        }
        
        for (int r = 0; r < 4; r++) {
            int nx = cx + dx[r];
            int ny = cy + dy[r];
            if (!in_boundary(nx, ny, dir)) continue;
            if (dir && (visited[nx][ny] == 3 || visited[nx][ny] == 2)) continue;
            if (!dir && (visited[nx][ny] == 3 || visited[nx][ny] == 1)) continue;
            
            q.push({{nx,ny}, {dir, depth+1}});
            if (dir) visited[nx][ny] += 2;
            else visited[nx][ny] += 1;
            result = max(result, depth+1);
        }
        
        bool dircpy = dir;
        if (is_rotatable(cx, cy)) {
            dircpy = !dircpy;
            if (dircpy && (visited[cx][cy] == 2 || visited[cx][cy] == 3)) continue;
            if (!dircpy && (visited[cx][cy] == 1 || visited[cx][cy] == 3)) continue;
            q.push({{cx,cy},{dircpy, depth+1}});
            if (dircpy) visited[cx][cy] += 2;
            else visited[cx][cy] += 1;
            result = max(result, depth+1);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //입력을 받음
    cin >> n;
    //초기 통나무의 좌표를 initialB 배열에 집어넣고, 그 자리를 공백 (0)으로 대체함
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            if (temp == 'B') {
                temp = '0';
                initialB.push_back({i, j});
            }
            area[i][j] = temp;
        }
    }
    int initialX = 0, initialY = 0;
    bool rotation = false;                        //false = 가로 (x, i가 같음), true = 세로 (y, j가 같음)
    for (int i = 0; i < 3; i++) {
        initialX += initialB[i].first;
        initialY += initialB[i].second;
    }
    initialX /= 3;
    initialY /= 3;
    if (initialB[0].first == initialB[1].first && initialB[1].first == initialB[2].first)
        rotation = false;                       //x(i)가 같은 경우, 즉 통나무가 가로인 경우
    else if (initialB[0].second == initialB[1].second && initialB[1].second == initialB[2].second)
        rotation = true;                        //y(j)가 같은 경우, 즉 통나무가 세로인 경우
    int result = bfs(initialX, initialY, rotation);
    if (result == 1e9) cout << 0;
    else cout << result << '\n';
    return 0;
}

