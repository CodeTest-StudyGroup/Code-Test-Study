import copy
from itertools import combinations
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = 1e9


def change_array(array, location):  # 바이러스 놓기
    for i, j in location:
        array[i][j] = "*"
    return array


def bfs(array):
    global result
    q = deque()
    count = 0  # 빈칸의 개수
    for i in range(n):
        for j in range(n):
            if array[i][j] == "*":
                q.append((i, j, 0))
            elif array[i][j] == 0:
                count += 1

    while q:
        x, y, cnt = q.popleft()
        if cnt > result:
            return
        if count == 0:
            break
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if array[nx][ny] == 0:
                    array[nx][ny] = -(cnt + 1)
                    q.append((nx, ny, cnt + 1))
                    count -= 1
                elif array[nx][ny] == 2:
                    array[nx][ny] = -(cnt + 1)
                    q.append((nx, ny, cnt + 1))
                elif array[nx][ny] != "*" and array[nx][ny] < -(cnt + 1):
                    array[nx][ny] = -(cnt + 1)
                    q.append((nx, ny, cnt + 1))
                elif array[nx][ny] == "*":
                    array[nx][ny] = -(cnt + 1)
                    q.append((nx, ny, cnt + 1))

    # 모두 바이러스로 바꼈는지 확인
    answer = 0
    for i in range(n):
        for j in range(n):
            if array[i][j] == 0:
                return -1
            elif array[i][j] != "*" and array[i][j] < 0:
                answer = max(answer, abs(array[i][j]))

    result = min(result, answer)


if __name__ == "__main__":
    n, m = map(int, input().split())  # 연구소의 크기, 바이러스의 개수
    array = [list(map(int, input().split())) for _ in range(n)]

    # 바이러스를 놓을 수 있는 위치 탐색
    location = []
    for i in range(n):
        for j in range(n):
            if array[i][j] == 2:
                location.append((i, j))

    # 모든 경우 bfs 탐색
    result = INF
    for data in list(combinations(location, m)):
        arr = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                arr[i][j] = array[i][j]
        arr = change_array(arr, data)
        bfs(arr)

    # 출력
    if result == INF:
        print(-1)
    else:
        print(result)
