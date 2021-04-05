#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 200
#define MAX_T 1001

int n, t;
vector < pair <int, int > > fields;
int dp[MAX_T][MAX_N];
int cost[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    //사냥터의 수 n과 방학 기간 t를 입력받아 저장
    cin >> n >> t;
    //각 사냥터의 요구 경험치 c와 시간당 획등 경험치 e를 입력받아 저장
    for (int i = 0; i < n; i++) {
        int tempC, tempE;
        cin >> tempC >> tempE;
        fields.push_back({tempC, tempE});
        //최초 사냥터 후보
        if (tempC == 0) {
            dp[0][i] = 0;
        }
    }
    //각 사냥터 간 이동 시간을 입력받아 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    //방학 각 날짜를 기준으로 루프를 돌며,
    for (int i = 1; i <= t; i++) {
        //각 사냥터에 대해,
        for (int j = 0; j < n; j++) {
            //전날 해당 사냥터에서 사냥했다면,
            if (dp[i-1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + fields[j].second);
            //새 사냥터에 오기 전 날짜
            for (int k = 0; k < n; k++) {
                int prev = i - cost[k][j];
                //날짜는 음수가 될 수 없으며 둘이 같은 경우 cost가 0이므로 고려하지 않음
                if (j == k || prev < 0) continue;
                //이동 전 사냥터에서 사냥을 했고 해당 사냥터 경험치 누적값이 다음 사냥터의 요구 경험치를 충족한다면,
                if (dp[prev][k] != -1 && dp[prev][k] >= fields[j].first)
                    dp[i][j] = max(dp[i][j], dp[prev][k]);
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dp[i][j]);
        }
    }
    cout << result;
    
    return 0;
}