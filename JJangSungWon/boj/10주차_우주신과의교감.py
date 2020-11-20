import heapq
import sys
import math


def find_parent(x, parent):
    if x != parent[x]:
        return find_parent(parent[x], parent)
    else:
        return parent[x]


def union_parent(a, b, parent):
    a = find_parent(a, parent)
    b = find_parent(b, parent)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    coordinates = [[0, 0]] + [list(map(int, sys.stdin.readline().split())) for _ in range(n)]  # 좌표 입력
    parent = [i for i in range(n + 1)]
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        union_parent(a, b, parent)

    # 크루스칼 알고리즘
    distance = []  # 모든 지점 사이의 거리를 삽입한다.
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            if i != j:
                d = math.sqrt(pow(abs(coordinates[j][1] - coordinates[i][1]), 2) + pow(abs(coordinates[j][0] - coordinates[i][0]), 2))
                heapq.heappush(distance, (d, i, j))

    result = 0
    while distance:
        d, a, b = heapq.heappop(distance)
        if find_parent(a, parent) != find_parent(b, parent):
            union_parent(a, b, parent)
            result += d

    print(format(result, ".2f"))