#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e9;
const int MAX = 200000;
int n, m, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i < m; ++i) dp[0][i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = i + 1; k <= min(i + d, n - 1); ++k) {
                int s = max(0, j - d + k - i);
                int e = min(j + d - k + i, m - 1);
                for (int l = s; l <= e; ++l) {
                    dp[k][l] = max(dp[k][l], arr[i][j] * arr[k][l] + dp[i][j]);
                }
            }
        }
    }
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
    return 0;
}