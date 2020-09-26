#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int N;
int W[200001];
int dp[200001][2];
bool visit[200001];

vector< vector<int> > node;

// dp[X][hasMento] = X가 X의 사수와 멘토릴 맺을 때, 혹은
// 맺지 않을 때 X의 서브트리에서의 시너지 합의 최댓값

int dfs(int cur, int hasMentor) {

	int& ret = dp[cur][hasMentor];

	// 이미 방문한 적이 있을 경우 바로 반환
	if (ret != -1) return ret;

	// 방문하지 않았을 경우 계산 시작
	int sum = 0;
	ret = 0;

	// dp[X][1] 일 때에는 X의 자식 노드 c1, c2, .. 에 대해 dp[c1][0] + dp[c2][0] +..을 구한다.
	// 즉, X의 자식노드 c1은 사수인 X와 멘토링을 맺지 않았으므로 = dp[c1][0]
	for (auto next : node[cur]) {
		sum = sum + dfs(next, 0);
	}
	ret = sum;
	if (hasMentor == 1) return sum;

	// hasMentor
	for (auto next : node[cur]) {
		// cur과 그 자식노드 next를 멘토링으로 묶었을 경우
		ret = max(ret, sum - dfs(next, 0) + dfs(next, 1) + W[cur] * W[next]);
	}
	return ret;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	node.resize(N + 1);

	for (int i = 2; i <= N; i++) {
		int input;
		cin >> input;
		node[input].push_back(i); // 방향성이 존재
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		cin >> W[i];
	}

	cout << dfs(1, 0);

	return 0;
}