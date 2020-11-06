#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 9999999999
typedef long long ll;

int N, M, D;
vector<vector<ll>> MAP;
vector<vector<ll>> dp;

void cal_dp(int x, int y) {
    //현재 칸에서 이동거리가 D이하인 칸으로 이동
	for (int i = x + 1; i <= x + D; i++) {
		for (int j = y - D + 1; j <= y + D - 1; j++) {
            //배열의 범위를 벗어나지 않고
			if (i >= 0 && i < N && j >= 0 && j < M) {
                //칸 사이의 이동거리가 D이하이면
				if (i - x + abs(y - j) <= D) {
                        //배열 값 갱신
						dp[i][j] = max(dp[i][j], dp[x][y] + (MAP[x][y] * MAP[i][j]));
				}
			}
		}
	}
}

int main() {
	ll answer = -INF;

	cin >> N >> M >> D;

	MAP.assign(N, vector<ll>(M));
    //DP배열은 -INF로 초기화 (점수가 음수일 수 있기 때문에)
	dp.assign(N, vector<ll>(M, -INF));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
    //첫번째행의 DP값은 0으로 초기화
	for (int i = 0; i < M; i++) {
		dp[0][i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			cal_dp(i, j);
		}
	}

	for (int i = 0; i < M; i++) {
		answer = max(answer, dp[N - 1][i]);
	}

	cout << answer;
}

