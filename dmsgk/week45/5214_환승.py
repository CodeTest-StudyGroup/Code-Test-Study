# 환승

import sys
from collections import deque


n, k, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+m+1)]

for i in range(1, m+1):
    row = list(map(int, input().split()))
    for j in range(k):
        graph[row[j]].append(n + i)
        graph[n + i].append(row[j])


def bfs(graph, n):
    visited = set()
    queue = deque([[1, 1]])  # [현재 노드번호, 방문한 도시 수]
    while queue:
        q, cnt = queue.popleft()
        if q == n:
            return cnt

        if q not in visited:
            visited.add(q)
            for nq in graph[q]:
                if nq > n:
                    queue.append([nq, cnt])
                else:
                    queue.append([nq, cnt+1])
    return -1


print(bfs(graph, n))