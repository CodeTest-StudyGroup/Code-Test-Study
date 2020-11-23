#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <algorithm>

#define pii pair<int,int>
#define INF 987654321

using namespace std;

int n, m, k;
vector<pii> node[1002];
priority_queue<int> que[1002];

void simulation(int start) {
	// dist 초기화
	priority_queue<pii, vector<pii>, greater<>> pq;
	que[start].push(0);
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curdist = pq.top().first;
		pq.pop();

		for (auto temp : node[cur]) {
			int next = temp.second;
			int nextdist = curdist + temp.first;

			// 각 노드의 큐에는 항상 최대 k개까지 가지고 있을 수 있다.
			if (que[next].size() < k) {
				que[next].push(nextdist);
				pq.push({ nextdist, next });
			}
			// 만약 큐에 k개 이상 가득 차 있었는데
			// 큐에 가장 큰 값이 현재 nextdist 값보다 더 컸을 경우,
			// 큐에서 가장 큰 값을 삭제하고, nextdist 값을 넣어서
			// k번째 값을 유지한다.
			else if (que[next].top() > nextdist) {
				que[next].pop();
				que[next].push(nextdist);
				pq.push({ nextdist, next });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ c,b });
	}

	simulation(1);

	for (int i = 1; i <= n; i++) {
		if (que[i].size() < k) {
			cout << -1 << '\n';
		}
		else if (que[i].size() >= k) {
			cout << que[i].top() << '\n';
		}
	}

	return 0;
}