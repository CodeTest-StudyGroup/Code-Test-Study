import sys
from math import log2
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline


def dfs(root):
    visited[root] = True
    for c in graph[root]:
        if visited[c]:
            continue
        dfs(c)
        # i: root color, j: child color
        for i in range(1, MAX):
            dp[root][i] += min(dp[c][j] for j in range(1, MAX) if j != i)
    for i in range(1, MAX):
        dp[root][i] += i


n = int(input())
MAX = int(log2(n)) + 2
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
dp = [[0] * MAX for _ in range(n+1)]

for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

dfs(1)
print(min(dp[1][1:]))
