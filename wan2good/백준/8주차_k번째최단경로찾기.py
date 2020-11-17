import heapq, sys

input = sys.stdin.readline

INF = 987654321

n, m, k = map(int, input().split())
graph = [[] for _ in range(n + 1)]
distance = [[] for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[0].append(0)
    while q:
        dist, now = heapq.heappop(q)

        for i in graph[now]:
            cost = dist + i[1]
            if len(distance[i[0] - 1]) < k:
                heapq.heappush(distance[i[0] - 1], -cost)
                heapq.heappush(q, (cost, i[0]))
            elif len(distance[i[0] - 1]) == k:
                a = heapq.heappop(distance[i[0] - 1])
                if -cost > a:
                    heapq.heappush(distance[i[0] - 1], -cost)
                    heapq.heappush(q, (cost, i[0]))
                else:
                    heapq.heappush(distance[i[0] - 1], a)


dijkstra(1)

for i in range(n):
    if len(distance[i]) < k:
        print(-1)
    else:
        print(-distance[i][0])
