import heapq


def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]


def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
        child_num[a] += child_num[b]
    else:
        parent[a] = b
        child_num[b] += child_num[a]


def find_child_num(x):
    if parent[x] != x:
        return find_child_num(parent[x])
    else:
        return child_num[x]


if __name__ == "__main__":
    n, m = map(int, input().split())  # 정점, 간선의 수
    parent = [-1] * (n + 1)
    child_num = [1] * (n + 1)  # 자기 자신포함 자식 개수
    for i in range(1, n + 1):
        parent[i] = i  # 자기 자신을 가르키도록
    edge = []
    total = 0  # 가중치 총합
    for _ in range(m):  # 간선 입력
        x, y, w = map(int, input().split())
        heapq.heappush(edge, (-w, x, y))  # 간선을 우선순위 큐(최대)로 관리
        total += w

    answer = 0
    current_total = 0
    for _ in range(m):
        w, x, y = heapq.heappop(edge)
        if find_parent(x) != find_parent(y):
            answer += find_child_num(x) * find_child_num(y) * (total - current_total)
            union_parent(x, y)
        current_total -= w
    if answer > 10 ** 9:
        answer %= 10 ** 9
    print(answer)

