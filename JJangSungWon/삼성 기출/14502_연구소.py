# boj 14502
# blog : jjangsungwon.tistory.com
import sys, copy
import itertools
from collections import deque


def bfs():
    q = deque(virus)
    visited = [[0] * M for _ in range(N)]

    while q:
        row, col = q.popleft()

        # 상
        if row - 1 >= 0 and temp_arr[row - 1][col] == 0 and visited[row - 1][col] == 0:
            visited[row - 1][col] = 1
            temp_arr[row - 1][col] = 2
            q.append([row - 1, col])

        # 하
        if row + 1 < N and temp_arr[row + 1][col] == 0 and visited[row + 1][col] == 0:
            visited[row + 1][col] = 1
            temp_arr[row + 1][col] = 2
            q.append([row + 1, col])

        # 좌
        if col - 1 >= 0 and temp_arr[row][col - 1] == 0 and visited[row][col - 1] == 0:
            visited[row][col - 1] = 1
            temp_arr[row][col - 1] = 2
            q.append([row, col - 1])

        # 우
        if col + 1 < M and temp_arr[row][col + 1] == 0 and visited[row][col + 1] == 0:
            visited[row][col + 1] = 1
            temp_arr[row][col + 1] = 2
            q.append([row, col + 1])


if __name__ == "__main__":

    N, M = map(int, input().split())
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    virus = []
    # 벽을 세울 수 있느 후보
    temp = []
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 0:
                temp.append([i, j])
            elif arr[i][j] == 2:
                virus.append([i, j])  # 바이러스 위치
    result = list(itertools.combinations(temp, 3))

    min_area = -1
    # 후보 개수 만큼 진행
    for k in range(len(result)):
        temp_arr = copy.deepcopy(arr)

        for i in range(3):
            temp_arr[result[k][i][0]][result[k][i][1]] = 1  # 벽 세우기

        # 바이러스 전파 시작
        bfs()

        cnt = 0
        for i in range(N):
            for j in range(M):
                if temp_arr[i][j] == 0:
                    cnt += 1
        min_area = max(min_area, cnt)
    print(min_area)
