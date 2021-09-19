import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

graph = [[] for _ in range(n+1)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(node):
    distance = [0] * (n + 1)
    visit[node] = 1
    q = deque([node])

    while q:
        nod = q.popleft()
        for i in graph[nod]:
            if visit[i] == -1:
                visit[i] = 1
                distance[i] = max(distance[nod] + 1, distance[i])
                q.append(i)
    return distance.index(max(distance)), max(distance)

visit = [-1] * (n + 1)
node1, dist = bfs(1)

visit = [-1] * (n + 1)
node2, dist = bfs(node1)

print((1 + dist) // 2)