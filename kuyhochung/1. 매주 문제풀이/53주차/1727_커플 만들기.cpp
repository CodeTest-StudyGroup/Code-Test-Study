#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1001

int n, m, temp;
vector<int> men;
vector<int> women;
int answer = 1e9;
int dp[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        men.push_back(temp);
    }
    for (int j = 0; j < m; j++) {
        cin >> temp;
        women.push_back(temp);
    }
    
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    
    //dp 계산 수행
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //무조건 커플
            if (i == j) {
                dp[i][j] = dp[i-1][j-1] + abs(men[i-1] - women[j-1]);
            }
            //커플이거나 i번째 남자가 솔로로 남는 경우
            else if (i > j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(men[i-1] - women[j-1]));
            }
            //커플이거나 j번째 여자가 솔로로 남는 경우
            else if (j > i) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(men[i-1] - women[j-1]));
            }
        }
    }
    
    cout << dp[n][m];
    return 0;
}
