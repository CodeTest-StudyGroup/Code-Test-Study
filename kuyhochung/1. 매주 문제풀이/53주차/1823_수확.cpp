#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 2001

int n, temp;
vector<int> rice;
int dp[MAX_N][MAX_N];

int get_dp (int left, int right, int count) {
    if (left > right) return 0;
    if (dp[left][right] != 0) return dp[left][right];
    
    return dp[left][right] = max(get_dp(left+1, right, count+1) + rice[left] * count, get_dp(left, right-1, count+1) + rice[right] * count);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    rice.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        rice.push_back(temp);
    }
    
    cout << get_dp(1, n, 1);
    return 0;
}
