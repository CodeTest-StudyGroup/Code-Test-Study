#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 501

int n;
vector<pair<int, int> > matrix;
int dp[MAX_N][MAX_N] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    matrix.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int row, column;
        cin >> row >> column;
        matrix.push_back({row, column});
    }
    
    //dp배열에 초기값 기록하기
    for (int i = 1; i < n; i++) {
        dp[i][i+1] = matrix[i].first * matrix[i].second * matrix[i+1].second;
    }
    
    //dp를 이용한 계산
    for (int m = 2; m <= n; m++) {
        for (int i = 1; i <= n-m; i++) {
            int j = i + m;
            for (int k = i; k < j; k++) {
                int result = dp[i][k] + dp[k+1][j] + (matrix[i].first * matrix[k].second * matrix[j].second);
                if (!dp[i][j] || dp[i][j] > result) dp[i][j] = result;
            }
        }
    }
    
    cout << dp[1][n];
    return 0;
}
