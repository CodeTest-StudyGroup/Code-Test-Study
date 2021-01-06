import sys


INF = 1E9


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    maps = [[INF] * n for _ in range(n)]
    for i in range(n):
        maps[i][i] = 0

    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        maps[b - 1][a - 1] = 1

    for k in range(n):
        for i in range(n):
            for j in range(n):
                maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j])

    result = []
    for i in range(n):
        cnt = 0
        for j in range(n):
            if maps[j][i] == INF and maps[i][j] == INF:
                cnt += 1
        result.append(cnt)

    for i in range(n):
        print(result[i])
