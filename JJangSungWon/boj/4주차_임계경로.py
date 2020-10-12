from collections import deque
import sys


def topological(start):
    q = deque()
    q.append(start)

    while q:
        index = q.popleft()
        for data in graph[index]:
            indegree[data[0]] -= 1
            time[data[0]] = max(time[data[0]], time[index] + data[1])
            if indegree[data[0]] == 0:
                q.append(data[0])

    # 1분도 쉬지 않고 달려야 하는 도로의 수 찾기
    edge = set()
    q = deque()
    q.append(end)
    while q:
        index = q.popleft()
        for data in reverse_graph[index]:
            if time[data[0]] == time[index] - data[1]:
                if (index, data[0]) not in edge:
                    edge.add((index, data[0]))
                    q.append(data[0])
    return len(edge)


if __name__ == "__main__":
    n = int(input())
    m = int(input())

    graph = [[] for _ in range(n + 1)]
    reverse_graph = [[] for _ in range(n + 1)]
    indegree = [0] * (n + 1)
    time = [0] * (n + 1)  # 각 지점에 도착하는데 걸리는 최대 시간

    for i in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        graph[a].append((b, c))
        reverse_graph[b].append((a, c))
        indegree[b] += 1
    start, end = map(int, input().split())

    cnt = topological(start)
    print(time[end])
    print(cnt)
