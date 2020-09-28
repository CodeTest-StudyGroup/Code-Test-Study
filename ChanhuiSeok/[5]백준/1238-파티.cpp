#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 987654321
#define pii pair<int, int>

using namespace std;
vector<pii>vec[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

/* 다익스트라 - (특정 정점) 에서 모든 정점까지의 최단거리 */

vector<int> dijkstra(int N, int start) {

	// 초기 dist값 INF
	vector<int> dist(N + 1, INF);

	// 초기 start 지점의 거리값 0으로 초기화
	dist[start] = 0;
	pq.push({ dist[start], start }); // 초기 데이터 push

	while (!pq.empty()) {
		int cur = pq.top().second; // 꺼낸 정점 번호
		int distance = pq.top().first; // 꺼낸 정점의 거리값
		pq.pop();

		// 이미, 담겨 있는 것보다 distance가 클 경우 넘어간다.
		if (dist[cur] < distance) continue;

		// 꺼낸 정점과 인접한 정점들을 모두 살펴본다.
		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i].first; // 인접한 다음 정점의 번호
			int nextDistance = vec[cur][i].second; // 다음 정점의 거리값

			if (distance + nextDistance < dist[next]) {
				dist[next] = distance + nextDistance;
				pq.push({ (distance + nextDistance), next });
			}
		}
	}
	return dist;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, X;
	cin >> N >> M >> X;
	// N은 정점, M은 간선의 수
	// X번 마을에서 시작

	int maxValue = -1;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}

	vector<int> Xtoi = dijkstra(N, X); // X에서 i까지 가는 거리 구하기 위해

	for (int i = 1; i <= N; i++) {

		vector<int> itoX = dijkstra(N, i); // i에서 X까지 가는 거리 구하기 위해
		int result_itoX = itoX[X]; // i번 학생이 X까지 가는 최단거리
		int result_Xtoi = Xtoi[i]; // i번 학생이 X에서 i번으로 오는 최단거리

		maxValue = max(maxValue, result_itoX + result_Xtoi);
	}

	cout << maxValue;
	return 0;
}