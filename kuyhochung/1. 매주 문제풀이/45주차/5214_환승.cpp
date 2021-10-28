#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int n, k, m;
int visited[101001];
vector<vector <int > > graph(101001);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			graph[temp].push_back(i + 100000);
			graph[i + 100000].push_back(temp);
		}
	}

	for (int i = 2; i < 101001; i++) {
		visited[i] = INF;
	}
	visited[1] = 0;

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int c = q.front();
		q.pop();
		
		for (int i = 0; i < graph[c].size(); i++) {
			if (visited[graph[c][i]] > visited[c] + 1) {
				visited[graph[c][i]] = visited[c] + 1;
				q.push(graph[c][i]);
			}
		}
	}

	cout << (visited[n] / 2) + 1;
	return 0;
}