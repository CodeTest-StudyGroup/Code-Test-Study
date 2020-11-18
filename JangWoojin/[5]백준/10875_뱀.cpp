#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int x, y;
};

struct Line {
    Pos a, b;
    int dir;  // 0=가로, 1=세로
    Line(Pos _a, Pos _b) : a(_a), b(_b) {
        dir = a.x == b.x ? 0 : 1;
        if (a.x > b.x || a.y > b.y) swap(a, b);
    }
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int INF = 1e9;
vector<Line> lines;

int move(int x, int y, int d) {
    int ret = INF;
    for (auto& line : lines) {
        Pos& a = line.a;
        Pos& b = line.b;
        if (line.dir == 0) {  // 가로
            switch (d) {
                case 0:
                    if (x == a.x && y < a.y) ret = min(ret, a.y - y);
                    break;
                case 1:
                    if (x < a.x && a.y <= y && y <= b.y)
                        ret = min(ret, a.x - x);
                    break;
                case 2:
                    if (x == a.x && y > a.y) ret = min(ret, y - a.y);
                    break;
                case 3:
                    if (x > a.x && a.y <= y && y <= b.y)
                        ret = min(ret, x - a.x);
                    break;
            }
        } else {  // 세로
            switch (d) {
                case 0:
                    if (a.x <= x && x <= b.x && y < a.y)
                        ret = min(ret, a.y - y);
                    break;
                case 1:
                    if (x < a.x && y == a.y) ret = min(ret, a.x - x);
                    break;
                case 2:
                    if (a.x <= x && x <= b.x && y > a.y)
                        ret = min(ret, y - a.y);
                    break;
                case 3:
                    if (x > a.x && y == a.y) ret = min(ret, x - a.x);
                    break;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, N;
    cin >> L >> N;
    lines.push_back({{-L - 1, -L - 1}, {-L - 1, L + 1}});
    lines.push_back({{-L - 1, -L - 1}, {L + 1, -L - 1}});
    lines.push_back({{-L - 1, L + 1}, {L + 1, L + 1}});
    lines.push_back({{L + 1, -L - 1}, {L + 1, L + 1}});

    int x = 0, y = 0, d = 0;
    long long ans = 0;
    for (int i = 0; i <= N; ++i) {
        int t = INF;
        char dir;
        if (i < N) cin >> t >> dir;
        int crushed = move(x, y, d);
        if (crushed <= t) {
            ans += crushed;
            break;
        }
        ans += t;
        int nx = x + dx[d] * t, ny = y + dy[d] * t;
        lines.push_back({{x, y}, {nx, ny}});
        d = (d + (dir == 'L' ? 3 : 1)) % 4;
        x = nx, y = ny;
    }
    cout << ans << endl;
    return 0;
}