from itertools import combinations
from collections import deque


def bfs(index, array):
    q = deque()
    q.append(index)
    visited = set()
    visited.add(index)

    while q:
        location = q.popleft()
        for index in graph[location]:
            if index in array and index not in visited:
                q.append(index)
                visited.add(index)

    if len(visited) == len(array):
        return True
    else:
        return False


if __name__ == "__main__":
    n = int(input())
    p = [None] + list(map(int, input().split()))
    graph = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        data = list(map(int, input().split()))
        graph[i] = data[1:]

    index = [i for i in range(1, n + 1)]

    answer = 1e9
    # 각 지역을 2개로 나누는 모든 경우 파악
    for i in range(1, len(index) // 2 + 1):
        for data in combinations(index, i):
            # a, b로 구간 나눔
            b = []
            a = list(data)
            for i in range(1, n + 1):
                if i not in a:
                    b.append(i)

            # a, b 연결 확인
            if bfs(a[0], a) and bfs(b[0], b):
                a_cnt, b_cnt = 0, 0
                # a 인구 수
                for i in range(len(a)):
                    a_cnt += p[a[i]]
                # b 인구 수
                for i in range(len(b)):
                    b_cnt += p[b[i]]

                answer = min(answer, abs(a_cnt - b_cnt))

    if answer == 1e9:
        print(-1)
    else:
        print(answer)



