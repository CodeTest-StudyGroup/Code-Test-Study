#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int map[MAX][MAX];
int c_map[MAX][MAX];
int n, m;

bool inRange(int x, int y) { return (0 <= x && x < n) && (0 <= y && y < m); }

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    map[sx][sy] = -1;
    q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inRange(nx, ny) && map[nx][ny] == 0) {
                map[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> map[i][j];

    bfs(0, 0);

    int ans = 0;
    while (1) {
        vector<pair<int, int>> cand;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (map[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int adj_x = i + dx[k];
                        int adj_y = j + dy[k];
                        if (inRange(adj_x, adj_y) && map[adj_x][adj_y] == -1)
                            cnt++;
                    }
                    if (cnt >= 2) cand.push_back({i, j});
                }
            }
        }
        if (cand.empty()) break;
        for (auto& c : cand) bfs(c.first, c.second);
        ans++;
    }

    cout << ans << endl;
    return 0;
}