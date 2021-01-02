from collections import deque
import sys
import heapq

INF = 1e9


def dijkstra():
    q = []
    heapq.heappush(q, (0, s))
    distance[s] = 0  # 출발지

    while q:  # 큐가 비어있지 않다면
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인하면서 거리 업데이트
        for i in graph[now]:
            cost = dist + graph[now][i]
            if cost < distance[i]:  # 해당 지점을 거치는 것이 거리가 짧은 경우
                distance[i] = cost
                heapq.heappush(q, (cost, i))


def bfs():
    q = deque()
    q.append(d)
    while q:
        v = q.popleft()
        if v == s:  # 시작점 도달
            continue  # break하면 다른 최단 경로를 확인할 수 없다.
        for pre_v, pre_c in r_graph[v]:
            if distance[pre_v] + graph[pre_v][v] == distance[v]:
                if (pre_v, v) not in remove_List:
                    remove_List.append((pre_v, v))
                    q.append(pre_v)


if __name__ == "__main__":
    while True:
        n, m = map(int, sys.stdin.readline().split())
        if n == 0 and m == 0:  # n과 m이 0이면 종료
            break
        s, d = map(int, sys.stdin.readline().split())  # 출발지, 도착지
        graph = [dict() for _ in range(n)]
        r_graph = [[] for _ in range(n)]
        for _ in range(m):
            u, v, p = map(int, sys.stdin.readline().split())  # 도로 정보 입력
            graph[u][v] = p
            r_graph[v].append((u, p))  # 경로를 추적하기 위해서 역순 저장

        # 다익스트라 알고리즘을 사용하여 최단 거리 찾기
        distance = [INF] * n
        dijkstra()

        # BFS를 사용하여 최단 경로 추적
        remove_List = list()
        bfs()

        # 최단 경로 제거
        for u, v in remove_List:
            del graph[u][v]

        # 다익스트라 알고리즘을 사용하여 최종 최단 경로 찾기
        distance = [INF] * n
        dijkstra()
        if distance[d] == INF:  # 거의 최단 경로가 없는 경우
            print(-1)
        else:
            print(distance[d])
