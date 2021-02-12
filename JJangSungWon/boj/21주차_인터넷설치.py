import heapq
import sys


INF = 1e15


def dijkstra(start, limit):
    q = []
    distance = [INF] * (n + 1)
    heapq.heappush(q, (0, start))  # (가중치, 인덱스)
    distance[start] = 0

    while q:
        cost, index = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[index] < cost:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인하면서 거리 업데이트
        for i in graph[index]:
            if i[0] > limit:
                if cost + 1 < distance[i[1]]:
                    distance[i[1]] = cost + 1
                    heapq.heappush(q, (cost + 1, i[1]))
            else:
                if cost < distance[i[1]]:
                    distance[i[1]] = cost
                    heapq.heappush(q, (cost, i[1]))

    # limit 보다 큰 가격 k개 이상이면 False
    if distance[n] > k:
        return False
    else:
        return Truegit


if __name__ == "__main__":
    n, p, k = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(p):
        a, b, c = map(int, sys.stdin.readline().split())
        graph[a].append((c, b))
        graph[b].append((c, a))

    left, right = 0, 1000001
    answer = INF
    while left <= right:
        mid = (left + right) // 2
        flag = dijkstra(1, mid)
        if flag:
            right = mid - 1
            answer = mid
        else:
            left = mid + 1

    if answer == INF:
        print(-1)
    else:
        print(answer)