#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 101

//성냥의 갯수로 만들 수 있는 1의 자리의 모음. 9개부터는 두자리 수가 최소가 된다.
int match_min[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
long long dp[MAX_N];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//dp 배열을 미리 작성한다.
	for (int i = 1; i < 9; i++) {
		dp[i] = match_min[i];
	}
	dp[6] = 6;

	for (int i = 9; i <= 100; i++) {
		dp[i] = dp[i - 2] * 10 + match_min[2];
		for (int j = 3; j < 8; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + match_min[j]);
		}
	}

	int testCase;
	cin >> testCase;
	while (testCase--) {
		int matches_have;
		cin >> matches_have;

		//가장 작은 수
		cout << dp[matches_have] << " ";

		//가장 큰 수
		if (matches_have % 2 == 0) {
			for (int i = 0; i < matches_have / 2; i++) {
				cout << 1;
			}
		}
		else {
			cout << 7;
			for (int i = 0; i < matches_have / 2 - 1; i++) {
				cout << 1;
			}
		}
		cout << '\n';
	}
	return 0;
}
