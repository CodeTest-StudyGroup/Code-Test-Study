#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int x, y;
};

struct State {
    int color, time;
};

const int EMPTY = 0;
const int GREEN = 3;
const int RED = 4;
const int FLOWER = 5;
const int MAX = 52;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

vector<pair<Pos, int>> cand;
int map[MAX][MAX];
int n, m, g, r, answer;

void bfs() {
    int cnt = 0;
    State state[MAX][MAX];
    memset(state, 0, sizeof(state));
    queue<Pos> q;
    for (int i = 0; i < cand.size(); ++i) {
        if (cand[i].second == EMPTY) continue;
        state[cand[i].first.x][cand[i].first.y] = {cand[i].second, 0};
        q.push(cand[i].first);
    }
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        State& cur = state[x][y];
        q.pop();
        if (cur.color == FLOWER) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            State& next = state[nx][ny];
            if (map[nx][ny] == 0 || next.color == FLOWER) continue;
            if (next.color == EMPTY) {
                next = {cur.color, cur.time + 1};
                q.push({nx, ny});
            } else if (next.color != cur.color && next.time == cur.time + 1) {
                cnt++;
                next.color = FLOWER;
            }
        }
    }
    answer = max(answer, cnt);
}

void backTracking(int idx, int green, int red) {
    if (green == g && red == r) {
        bfs();
        return;
    }
    for (int i = idx; i < cand.size(); ++i) {
        if (green < g) {
            cand[i].second = GREEN;
            backTracking(i + 1, green + 1, red);
            cand[i].second = EMPTY;
        }
        if (red < r) {
            cand[i].second = RED;
            backTracking(i + 1, green, red + 1);
            cand[i].second = EMPTY;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> g >> r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) cand.push_back({{i, j}, EMPTY});
        }
    }
    backTracking(0, 0, 0);
    cout << answer << endl;
    return 0;
}