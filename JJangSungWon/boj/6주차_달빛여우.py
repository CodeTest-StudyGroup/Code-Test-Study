import sys
import heapq

INF = 1e12


def dijkstra(distance, edge):
    q = []
    heapq.heappush(q, (0, 1))
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in edge[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    fox_graph = [[] for _ in range(n + 1)]
    wolf_graph = [[] for _ in range(2 * n + 1)]
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        fox_graph[a].append((b, 2 * c))
        fox_graph[b].append((a, 2 * c))
        wolf_graph[a].append((n + b, c))
        wolf_graph[n + a].append((b, 4 * c))
        wolf_graph[b].append((n + a, c))
        wolf_graph[n + b].append((a, 4 * c))

    # 여우 다익스트라
    fox_distance = [INF] * (n + 1)  # 여우가 각 지점에 이동하는 최소 거리
    fox_distance = dijkstra(fox_distance, fox_graph)

    # 늑대 다익스트라
    wolf_distance = [INF] * (2 * n + 1)  # 늑대가 각 지점에 이동하는 최소 거리
    wolf_distance = dijkstra(wolf_distance, wolf_graph)

    cnt = 0
    for i in range(2, n + 1):
        if fox_distance[i] < min(wolf_distance[i], wolf_distance[i + n]):
            cnt += 1
    print(cnt)