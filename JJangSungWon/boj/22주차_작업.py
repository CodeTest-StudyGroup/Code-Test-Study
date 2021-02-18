import sys
from collections import deque


def topological():
    q = deque()
    # 진입 차수가 0인 값 q에 삽입
    for i in range(1, n + 1):
        if len(indegree[i]) == 0:
            q.append((i, time[i]))

    total = 0
    temp = [0] * (n + 1)
    temp[1] = time[1]

    # 위상 정렬
    while q:
        index, cost = q.popleft()
        total = max(total, cost)
        # index와 연결된 부분 처리
        for i in range(1, n + 1):
            if index in indegree[i]:
                indegree[i].remove(index)
                temp[i] = max(temp[i], cost + time[i])
                if len(indegree[i]) == 0:
                    q.append((i, temp[i]))
                    total = max(total, temp[i])
    return total


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    indegree = [[] for _ in range(n + 1)]
    time = [0] * (n + 1)  # 작업 시간
    for i in range(n):
        array = list(map(int, input().split()))
        time[i + 1] = array[0]
        for j in range(array[1]):
            indegree[array[2 + j]].append(i + 1)

    answer = topological()
    print(answer)