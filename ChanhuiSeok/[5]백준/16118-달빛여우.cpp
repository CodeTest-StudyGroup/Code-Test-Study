#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

#define pdd pair<long long,int>
#define ppdd pair<pair<long long,int>, int>

#define fast 1
#define slow 0

using namespace std;

const long long INF = 2e10;
int N, M;
vector<pair<long long, int>> node[4002];
long long dist_f[4002];
long long dist_w[4002][2];
set<int> answer;

void sim_wolf(int start) {
	priority_queue<ppdd, vector<ppdd>, greater<>> wolf_pq;
	dist_w[start][slow] = 0;

	// 늑대 다익스트라 (거리, 노드번호)
	// 처음에는 빠르게 달리기 시작하므로
	wolf_pq.push({ {0, start}, fast });

	while (!wolf_pq.empty()) {
		int cur = wolf_pq.top().first.second;
		long long cur_dist = wolf_pq.top().first.first;
		int mode = wolf_pq.top().second;

		wolf_pq.pop();

		if (dist_w[cur][!mode] < cur_dist) continue;

		// 빠르게 달려왔을 경우, 다음은 느리게 가야 한다.	
		for (auto tmp : node[cur]) {
			int next = tmp.second;
			long long next_dist = tmp.first;

			if (mode == fast)
				next_dist = next_dist / 2;
			else
				next_dist = next_dist * 2;

			if (dist_w[next][mode] > next_dist + dist_w[cur][!mode]) {
				dist_w[next][mode] = next_dist + dist_w[cur][!mode];
				wolf_pq.push({ {dist_w[next][mode], next}, !mode });
			}
		}
	}
}

void sim_fox(int start) {
	priority_queue<pdd, vector<pdd>, greater<>> fox_pq;
	// 초기화
	dist_f[start] = 0;

	// 여우 다익스트라 (거리, 노드번호)
	fox_pq.push({ 0, start });

	while (!fox_pq.empty()) {
		int cur = fox_pq.top().second;
		long long cur_dist = fox_pq.top().first;

		fox_pq.pop();
		if (dist_f[cur] < cur_dist) continue;

		// 인접한 노드 모두 살펴보기
		for (auto& tmp : node[cur]) {
			long long next_dist = tmp.first;
			int next = tmp.second;

			if (dist_f[next] > dist_f[cur] + next_dist) {
				dist_f[next] = dist_f[cur] + next_dist;
				fox_pq.push({ dist_f[next], next });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		long long d;
		cin >> a >> b >> d;
		node[a].push_back({ d * 2, b });
		node[b].push_back({ d * 2, a });
	}

	for (int i = 1; i <= N; i++) {
		dist_w[i][fast] = INF;
		dist_w[i][slow] = INF;
		dist_f[i] = INF;
	}

	sim_fox(1);
	sim_wolf(1);

	int answer = 0;
	// 달빛 여우가 더 짧은 번호가 있나 살펴보기
	for (int i = 1; i <= N; i++) {
		if (dist_f[i] < dist_w[i][fast] &&
			dist_f[i] < dist_w[i][slow]) {
			answer++;
		}
	}

	cout << answer;
	return 0;
}