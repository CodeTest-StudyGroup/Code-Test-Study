#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <bitset>
#include <map>

using namespace std;

long long N, M, D;
long long** arr;
long long** dp;
//long long arr[500][500];
//long long dp[500][500];

long long INF = 1e20;

void simulation(int r, int c) {
	// 현재 칸 arr[r][c]에 대하여 D 거리 이내에 갈 수 있는 칸 살펴보기

	for (int row = r + 1; row <= r + D; row++) {

		for (int col = c - D + 1; col <= c + D - 1; col++) {
			if (row >= 0 && col >= 0 && row < N && col < M &&
				abs((long long)row - r) + abs((long long)col - c) <= D) {
				// 기존 * 갈 곳의 곱
				long long value = arr[r][c] * arr[row][col];
				dp[row][col] = max(dp[row][col], dp[r][c] + value);
			}
		}

	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> D;


	arr = new long long* [N];
	dp = new long long* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new long long[M];
		dp[i] = new long long[M];
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			dp[i][j] = -INF;
		}
	}
	for (int i = 0; i < M; i++) {
		dp[0][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			simulation(i, j);
		}
	}

	long long maxVal = -INF;
	for (int k = 0; k < M; k++) {
		maxVal = max(maxVal, dp[N - 1][k]);
	}

	cout << maxVal;

	return 0;

}
