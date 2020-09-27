dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    if x == m - 1 and y == n - 1:
        return 1
    elif dp[x][y] != -1:
        return dp[x][y]
    else:
        dp[x][y] = 0
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < m and 0 <= ny < n:
                if array[nx][ny] < array[x][y]:
                    dp[x][y] += bfs(nx, ny)
        return dp[x][y]


if __name__ == "__main__":
    m, n = map(int, input().split())
    array = [list(map(int, input().split())) for _ in range(m)]

    dp = [[-1] * n for _ in range(m)]

    # bfs + dp 탐색
    bfs(0, 0)

    print(dp[0][0])
