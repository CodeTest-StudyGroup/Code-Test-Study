#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1001
#define INF 1e9

int n, m;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int startX, startY;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool in_boundary(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				startX = i; startY = j;
				visited[i][j] = 0;
			}
		}
	}

	queue<pair<int, int> > q;
	q.push({ startX, startY });
	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = currentX + dx[dir];
			int ny = currentY + dy[dir];
			if (!in_boundary(nx, ny)) continue;
			if (map[nx][ny] == 0 || map[nx][ny] == 2) continue;

			if (visited[currentX][currentY] + 1 < visited[nx][ny]) {
				visited[nx][ny] = visited[currentX][currentY] + 1;
				q.push({ nx, ny });
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == INF) {
				if (map[i][j] == 1) cout << -1;
				else if (map[i][j] == 0) cout << 0;
			}
			else cout << visited[i][j];
			cout << " ";
		}
		cout << '\n';
	}

	return 0;
}