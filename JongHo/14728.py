import sys
input = sys.stdin.readline

n, t = map(int, input().split())

ans = [[0 for _ in range(t+1)] for _ in range(n)]

for i in range(n):
    k, s = map(int, input().split())
    for j in range(1, t + 1):
        if j >= k:
            ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - k] + s)
        else:
            ans[i][j] = ans[i - 1][j]
print(max(ans[-1]))