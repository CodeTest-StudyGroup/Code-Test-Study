#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 50001

int repeat = 3;
int dp[MAX_N] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (repeat--) {
		int total_cost = 0, coins_kind = 0;
		vector<pair<int, int> > coins;

		cin >> coins_kind;
		int value, count;
		for (int i = 0; i < coins_kind; i++) {
			cin >> value >> count;
			coins.push_back({ value, count });
			total_cost += value * count;
		}

		if (total_cost % 2 == 1) {
			cout << "0\n";
		}
		else {
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;

			for (auto& next : coins) {
				for (int i = 50000; i >= next.first; i--) {
					if (dp[i - next.first] != 0) {
						for (int j = 0; (j < next.second) && (i + j * next.first <= 50000); j++) {
							dp[i + j * next.first] = 1;
						}
					}
				}
			}

			cout << dp[total_cost / 2] << '\n';
		}

	}

	return 0;
}