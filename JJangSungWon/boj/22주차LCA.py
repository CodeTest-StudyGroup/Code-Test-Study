import sys
import math
sys.setrecursionlimit(10**9)


MAX = 100001


def dfs(x, depth):
    c[x] = True
    d[x] = depth
    for i in range(len(tree[x])):
        y = tree[x][i]
        if c[y]:
            continue
        parent[y][0] = x
        dfs(y, depth + 1)


# 전체 부모 관계를 설정하는 함수입니다.
def setParent():
    dfs(1, 1)  # 루트를 1로 설정합니다.
    for j in range(1, h + 1):
        for i in range(1, MAX):
            parent[i][j] = parent[parent[i][j - 1]][j - 1]


def LCA(x, y):
    # y가 더 깊도록 설정합니다.
    if d[x] > d[y]:
        x, y = y, x

    # 두 노드의 깊이를 동일하도록 맞춥니다.
    for i in range(h, -1, -1):
        if d[y] - d[x] >= (1 << i):
            y = parent[y][i]

    # 부모가 같을 경우 반환합니다.
    if x == y:
        return x
    for i in range(h, -1, -1):
        # 조상을 향해 거슬러 올라갑니다.
        if parent[x][i] != parent[y][i]:
            x = parent[x][i]
            y = parent[y][i]

    # 바로 부모가 찾고자 하는 조상입니다.
    return parent[x][0]


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    tree = [[] for _ in range(MAX)]
    d = [0] * MAX
    c = [False] * MAX
    h = int(math.log2(MAX)) + 1
    parent = [[0 for _ in range(h + 1)] for _ in range(MAX)]
    for _ in range(n - 1):
        a, b = map(int, sys.stdin.readline().split())
        tree[a].append(b)
        tree[b].append(a)

    setParent()

    m = int(sys.stdin.readline())
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        print(LCA(a, b))
