#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int W[10001];
int dp[10001][2];
bool visit[10001];

vector< vector<int> > v;

/* 문제에서 방향성이 없는 그래프 정보를 주기 때문에
dfs 탐색하면서 한 번이라도 방문한 곳을 다시는 가지 않게 한다면
트리에서 부모 - 자식으로 가는 형태를 만들 수 있습니다. */

void dfs(int cur) {

	// 이미 방문한 곳은 가면 안 된다.
	if (visit[cur]) return;

	// 처음 들어온 cur 노드에 대해 일반 마을과 우수 마을일 때 인구수를 초기화
	// 우수 마을을 구하는 것이므로 인구수는 우수마을일 때만 설정한다.
	visit[cur] = true;
	dp[cur][0] = 0;
	dp[cur][1] = W[cur];

	// cur에 인접한 자식 노드들에 대하여
	for (auto next : v[cur]) {
		if (visit[next]) continue; // 방문 안 한 곳에만 간다.

		dfs(next); // 끝까지 타고 들어간다.

		// 일반 마을은 자식 마을이 우수거나, 자식 마을이 일반 마을이다.
		// 더 큰 쪽을 선택한다. 3번 조건은 여기서 해결이 된다.
		dp[cur][0] = dp[cur][0] + max(dp[next][0], dp[next][1]);

		// 현재 마을이 우수 마을이면, 자식은 반드시 일반 마을이어야 한다.
		dp[cur][1] = dp[cur][1] + dp[next][0];
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		W[i] = input;
	}

	v.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);

	return 0;
}