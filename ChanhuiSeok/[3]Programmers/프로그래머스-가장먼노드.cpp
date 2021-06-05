#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[20001];

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<int> list[20001];
	for (int i = 0; i < edge.size(); i++) {
		list[edge[i][0]].push_back(edge[i][1]);
		list[edge[i][1]].push_back(edge[i][0]);
	}

	queue<pair<int, int>> q;

	// 1번 노드에 연결된 것 미리 push 및 방문 표시
	visit[1] = 1;
	for (int i = 0; i < list[1].size(); i++) {
		q.push({ list[1][i], 1 });
		visit[list[1][i]] = 1;
	}

	int maxDepth = -1;
	int cnt = 0;

	// bfs
	while (!q.empty()) {

		int node = q.front().first;
		int depth = q.front().second;
		q.pop();

		for (int i = 0; i < list[node].size(); i++) {
			if (visit[list[node][i]] == 0) {
				q.push({ list[node][i],depth + 1 });
				visit[list[node][i]] = 1;

				if (depth + 1 > maxDepth) {
					maxDepth = depth + 1;
					cnt = 1;
				}
				else if (depth + 1 == maxDepth) {
					cnt += 1;
				}
			}
		}
	}

	return cnt;
}