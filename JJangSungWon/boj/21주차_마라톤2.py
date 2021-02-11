import sys


INF = 1e10
if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    point = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    distance = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            distance[i][j] = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1])

    dp = [[INF for _ in range(n)] for _ in range(k + 1)]
    dp[0][0] = 0

    # k = 0
    for i in range(1, n):
        dp[0][i] = dp[0][i - 1] + distance[i - 1][i]

    # k = 1, 2, ... k
    for i in range(1, k + 1):
        dp[i][0], dp[i][1] = 0, dp[i - 1][1]
        dp[i][i] = distance[0][i]
        for j in range(1, n):
            for m in range(i, 0, -1):
                if j - m - 1 < 0:
                    continue
                dp[i][j] = min(dp[i][j], dp[i - m][j - m - 1] + distance[j][j - m - 1], dp[i][j - 1] + distance[j - 1][j])

    print(dp[-1][-1])