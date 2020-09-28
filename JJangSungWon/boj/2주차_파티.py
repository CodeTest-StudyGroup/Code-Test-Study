import heapq

INF = 1e9


def dijkstra(start, distance):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인하면서 거리 업데이트
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


if __name__ == "__main__":
    n, m, x = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))

    # 다익스트라(X -> 모든 지점)
    distance_from_x = [INF] * (n + 1)
    dijkstra(x, distance_from_x)

    # 각 지점에서 X까지의 거리 파악 후 결과 도출
    answer = 0
    for i in range(1, n + 1):
        if i != x:
            distance = [INF] * (n + 1)
            dijkstra(i, distance)
            answer = max(answer, distance_from_x[i] + distance[x])
    print(answer)
