#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 101
#define MAX_T 10001

int N, T;
vector<pair<int, int> > subjects;
int dp[MAX_N][MAX_T] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //주어진 입력을 받는다.
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int k, s;
        cin >> k >> s;
        subjects.push_back({k, s});
    }
    
    for (int i = 1; i <= N; i++) {
        int study_time = subjects[i-1].first, credit = subjects[i-1].second;
        for (int j = 0; j <= T; j++) {
            if (j < study_time) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-study_time] + credit);
            }
        }
    }
    
    cout << dp[N][T];
    return 0;
}
