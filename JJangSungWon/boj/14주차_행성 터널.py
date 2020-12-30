import sys


def find_parent(x, parent):
    if x != parent[x]:
        parent[x] = find_parent(parent[x], parent)
    return parent[x]


def union_parent(a, b, parent):
    a = find_parent(a, parent)
    b = find_parent(b, parent)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


if __name__ == "__main__":
    # input
    n = int(sys.stdin.readline())
    c = []
    for i in range(n):
        x, y, z = map(int, sys.stdin.readline().split())
        c.append((x, y, z, i))  # 좌표값, 인덱스

    # 각 좌표별로 정렬한 후 거리를 계산해서 edge를 만든다.
    edges = []
    for i in range(3):
        c.sort(key=lambda x:x[i])
        for j in range(1, n):
            edges.append((abs(c[j - 1][i] - c[j][i]), c[j - 1][3], c[j][3]))

    parent = [i for i in range(n)]
    total = 0
    edges.sort()

    for i in range(len(edges)):
        if find_parent(edges[i][1], parent) != find_parent(edges[i][2], parent):
            union_parent(edges[i][1], edges[i][2], parent)
            total += edges[i][0]
    print(total)