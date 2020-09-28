import sys
sys.setrecursionlimit(10 ** 9)


def dfs(index, value):
    global answer, visited, far_index
    for i in range(len(graph[index])):
        if not visited[graph[index][i][0] - 1]:
            visited[graph[index][i][0] - 1] = True
            dfs(graph[index][i][0] - 1, value + graph[index][i][1])

    if answer < value:
        answer = value
        far_index = index
    answer = max(answer, value)


def find_diameter(index, value):
    global answer, visited
    # 자식 탐색
    for i in range(len(graph[index])):
        if not visited[graph[index][i][0] - 1]:
            visited[graph[index][i][0] - 1] = True
            dfs(graph[index][i][0] - 1, value + graph[index][i][1])

    # 부모 탐색
    for i in range(n):
        if i != index:
            for j in range(len(graph[i])):
                if graph[i][j][0] == index:
                    if not visited[graph[i][j][0] - 1]:
                        visited[graph[i][j][0] - 1] = True
                        dfs(graph[i][j][0] - 1, value + graph[i][j][1])

    answer = max(answer, value)


if __name__ == "__main__":
    n = int(input())
    graph = [[] for _ in range(n)]
    for i in range(n):
        array = list(map(int, input().split()))
        array = array[:-1]  # 오른쪽 값은 필요없다.
        for j in range(1, len(array), 2):
            graph[array[0] - 1].append((array[j], array[j + 1]))  # 인덱스, 길이

    # dfs 탐색 -> 1번 노드에서 가장 먼 지점 파악
    answer = 0
    visited = [False] * n
    visited[0] = True
    far_index = -1
    dfs(0, 0)

    # far_index에서 가장 먼 곳이 트리의 지름이다.
    visited = [False] * n
    visited[far_index] = True
    answer = 0
    find_diameter(far_index, 0)

    print(answer)
