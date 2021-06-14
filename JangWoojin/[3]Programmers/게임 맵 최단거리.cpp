#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool visited[MAX][MAX];
int n, m;

int solution(vector<vector<int>> maps) {
    int answer = -1;
    n = maps.size();
    m = maps[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            answer = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[nx][ny] && maps[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }
    return answer;
}