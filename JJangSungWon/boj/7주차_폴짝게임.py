import sys


if __name__ == "__main__":
    n, m, d = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    dp = [[-1e10] * m for _ in range(n)]
    for i in range(m):
        dp[0][i] = 0

    for i in range(1, n):
        for j in range(m):
            # dp[i, j] 계산
            for x in range(i - 1, -1, -1):
                if i - x > d:
                    break
                for y in range(d - (i - x) + 1):
                    if j + y < m:
                        dp[i][j] = max(dp[i][j], dp[x][j + y] + maps[i][j] * maps[x][j + y])
                    if j - y >= 0:
                        dp[i][j] = max(dp[i][j], dp[x][j - y] + maps[i][j] * maps[x][j - y])

    answer = -1e9
    for i in range(m):
        answer = max(answer, dp[n - 1][i])
    print(answer)