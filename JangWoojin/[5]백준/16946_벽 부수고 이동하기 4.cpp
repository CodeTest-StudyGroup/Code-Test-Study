#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define EMPTY 0
#define WALL 1

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX = 1000;
int map[MAX][MAX];
int answer[MAX][MAX];
int area[MAX * MAX / 2 + 10];
int n, m;

inline bool inRange(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int bfs(int x, int y, int area_no) {
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = area_no;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        sum++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inRange(nx, ny))
                continue;

            if (map[nx][ny] == EMPTY) {
                map[nx][ny] = area_no;
                q.push({nx, ny});
            }
        }
    }
    return sum;
}

void calc(int x, int y) {
    set<int> s;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inRange(nx, ny) && map[nx][ny] != WALL)
            s.insert(map[nx][ny]);
    }
    int cnt = 1;
    for (auto area_no : s)
        cnt += area[area_no];
    answer[x][y] = cnt % 10;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);

    for (int i = 0, area_no = 2; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == EMPTY) {
                area[area_no] = bfs(i, j, area_no);
                area_no++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == WALL) {
                calc(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}
