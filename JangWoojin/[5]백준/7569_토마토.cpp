#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

const int dx[] = {0, 0, 1, 0, -1, 0};
const int dy[] = {0, 0, 0, 1, 0, -1};
const int dz[] = {-1, 1, 0, 0, 0, 0};

int a[100][100][100];
int n, m, h;

bool inRange(int x, int y, int z) {
    return (0 <= x && x < m) && (0 <= y && y < n) && (0 <= z && z < h);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pipii> q;

    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[k][i][j];
                if (a[k][i][j] == 1) {
                    q.push({k, {j, i}});
                }
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int z = q.front().first;
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (inRange(nx, ny, nz) && a[nz][ny][nx] == 0) {
                    a[nz][ny][nx] = 1;
                    q.push({nz, {nx, ny}});
                }
            }
        }
        ans++;
    }

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[k][i][j] == 0) ans = -1;
            }
        }
    }

    cout << (ans > 0 ? ans - 1 : ans) << endl;

    return 0;
}