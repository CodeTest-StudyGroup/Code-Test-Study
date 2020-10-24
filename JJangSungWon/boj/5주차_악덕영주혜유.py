import heapq


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


def kruskal(arr):
    result = 0  # 모든 마을을 연결하는 비용
    cnt = 0
    parent = [0] * n
    for i in range(n):
        parent[i] = i  # 자기 자신을 가르키도록

    while cnt < n - 1:
        cost, a, b = heapq.heappop(arr)
        if find_parent(parent, a) != find_parent(parent, b):
            edge[a].append((b, cost))
            edge[b].append((a, cost))
            distance[a][b] = cost
            distance[b][a] = cost
            union_parent(parent, a, b)
            result += cost
            cnt += 1
    return result


def dfs(now, pre):
    global max_distance
    result = 0
    second = 0
    for nxt, cost in edge[now]:
        if nxt == pre:
            continue
        temp = dfs(nxt, now) + cost
        if temp > result:
            second = result
            result = temp
        elif temp > second:
            second = temp

    max_distance = max(max_distance, result + second)
    return result


if __name__ == "__main__":
    n, k = map(int, input().split())  # 정점의 수, 간선의 수
    min_heap_edge = []  # 간선 저장(최소 힙)
    edge = [[] for _ in range(n)]
    for _ in range(k):
        a, b, cost = map(int, input().split())
        heapq.heappush(min_heap_edge, (cost, a, b))

    # 교역 설치
    distance = [[0] * n for _ in range(n)]
    min_cost = kruskal(min_heap_edge)
    max_distance = 0
    dfs(0, -1)

    # 출력
    print(min_cost)
    print(max_distance)