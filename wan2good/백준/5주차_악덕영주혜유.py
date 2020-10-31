import sys, heapq

input = sys.stdin.readline


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


INF = 987654321

# input data
n, k = map(int, input().rstrip().split())
graph = [[] for i in range(n)]
distance = [INF] * n
edges = []

for _ in range(k):
    a, b, c = map(int, input().rstrip().split())
    heapq.heappush(edges, (c, a, b))

# 크루스칼
result = 0
parent = [0] * n
for i in range(n):
    parent[i] = i
cnt = 0
while cnt < n - 1:
    c, a, b = heapq.heappop(edges)
    if find_parent(parent, a) != find_parent(parent, b):
        graph[a].append((b, c))
        graph[b].append((a, c))
        union_parent(parent, a, b)
        result += c
        cnt += 1

print(result)


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:  # 큐가 비어있지 않다면
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


result = 0
for i in range(n):
    dijkstra(i)
    result = max(result, max(distance))
    distance = [INF] * n

print(result)
