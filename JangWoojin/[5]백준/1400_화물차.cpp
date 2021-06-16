#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Light {
    char type;
    int a, b;

    Light(char type, int a, int b) : type(type), a(a), b(b) {}
};

struct Entry {
    int x, y, t;

    Entry(int x, int y, int t) : x(x), y(y), t(t) {}

    bool operator<(const Entry& rhs) const { return t > rhs.t; }

    bool operator==(const Entry& rhs) const { return x == rhs.x && y == rhs.y; }
};

const int MAX = 20;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
string map[MAX];
vector<Light> lights;
int n, m;

int bfs(Entry src, Entry dest) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<Entry> pq;
    pq.push(src);

    while (!pq.empty()) {
        Entry e = pq.top();
        pq.pop();

        if (visited[e.x][e.y]) continue;
        visited[e.x][e.y] = true;
        if (e == dest) return e.t;

        for (int i = 0; i < 4; i++) {
            int nx = e.x + dx[i];
            int ny = e.y + dy[i];
            int nt = e.t + 1;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (map[nx][ny] == '#' || map[nx][ny] == 'B') {
                pq.push(Entry(nx, ny, nt));
            } else if (isdigit(map[nx][ny])) {
                while (1) {
                    int idx = map[nx][ny] - '0';
                    int a = lights[idx].a;
                    int b = lights[idx].b;
                    int time = nt % (a + b);
                    if (time == 0) time += a + b;
                    char type;

                    if (lights[idx].type == '-')
                        type = time <= a ? '-' : '|';
                    else
                        type = time <= b ? '|' : '-';

                    if (type == '-' && i % 2 == 0) break;
                    if (type == '|' && i % 2 == 1) break;
                    nt++;
                }
                pq.push(Entry(nx, ny, nt));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        lights.clear();

        Entry src(0, 0, 0);
        Entry dest(0, 0, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> map[i];
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'A') {
                    src = Entry(i, j, 0);
                } else if (map[i][j] == 'B') {
                    dest = Entry(i, j, 0);
                } else if (isdigit(map[i][j])) {
                    cnt++;
                }
            }
        }

        while (cnt--) {
            char type;
            int temp, a, b;
            cin >> temp >> type >> a >> b;
            lights.push_back(Light(type, a, b));
        }

        int answer = bfs(src, dest);

        if (answer == -1)
            cout << "impossible" << endl;
        else
            cout << answer << endl;
    }
    return 0;
}
