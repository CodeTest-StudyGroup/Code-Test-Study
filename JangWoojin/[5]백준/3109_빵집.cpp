#include <iostream>
using namespace std;

const int dx[] = { -1, 0, 1 };
const int dy[] = { 1, 1, 1 };
string map[10001];
int r, c;

bool dfs(int x, int y) {
    if (y == c - 1)
        return 1;
    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || map[nx][ny] == 'x')
            continue;
        map[nx][ny] = 'x';
        if (dfs(nx, ny)) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        cin >> map[i];
    int answer = 0;
    for (int i = 0; i < r; ++i)
        answer += dfs(i, 0);
    cout << answer << endl;
    return 0;
}