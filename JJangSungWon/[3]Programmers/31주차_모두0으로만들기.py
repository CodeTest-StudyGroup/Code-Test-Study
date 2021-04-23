import sys

sys.setrecursionlimit(10 ** 8)


def dfs(idx, a):
    global visited, graph, answer
    now = a[idx]
    visited[idx] = True

    for index in graph[idx]:
        if visited[index] is False:
            now += dfs(index, a)
    answer += abs(now)
    return now


def solution(a, edges):
    global visited, graph, answer
    answer = 0

    if sum(a) != 0:
        return -1

    visited = [False] * len(a)
    graph = [[] for _ in range(len(a))]

    for x, y in edges:
        graph[x].append(y)
        graph[y].append(x)

    dfs(0, a)

    return answer