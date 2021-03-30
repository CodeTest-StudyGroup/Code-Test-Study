#include <iostream>
#include <cstring>

using namespace std;
#define MAX_N 501

int M, N;
int numbers[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    if (x < 0 || x >= M || y < 0 || y >= N)
        return 0;
    if (x == 0 && y == 0)
        return 1;

    dp[x][y] = 0;
    for (int k = 0; k < 4; k++) {
        int dx = x + moveX[k];
        int dy = y + moveY[k];
        if (numbers[dx][dy] > numbers[x][y])
            dp[x][y] += dfs(dx,dy);
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(M-1, N-1);

    return 0;
}