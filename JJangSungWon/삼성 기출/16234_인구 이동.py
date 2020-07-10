'''
 시간 제한 너무 빡세다..
'''

import sys
from _collections import deque

# 상, 하, 좌, 우
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def bfs(row, col):
    check = False
    visited = {(row, col)}
    q = deque([(row, col)])
    val, cnt = 0, 0

    while q:
        row, col = q.popleft()
        val += arr[row][col]
        cnt += 1
        for i in range(4):
            new_row, new_col = row + dy[i], col + dx[i]

            if 0 <= new_row < N and 0 <= new_col < N and (new_row, new_col) not in visited and L <= abs(arr[new_row][new_col] - arr[row][col]) <= R:
                q.append((new_row, new_col))
                visited.add((new_row, new_col))
                check = True
    return val // cnt, visited, check


def move():
    # 인구 이동
    cnt, pre_cnt = 0, 0
    while True:
        is_Move = False
        total_visited = set()
        temp = []
        for i in range(N):
            for j in range(N):
                if (i, j) not in total_visited:
                    value, visited, flag = bfs(i, j)
                    if flag:
                        is_Move = True
                    temp.append((value, visited))
                    total_visited |= visited

        for (value, visit) in temp:
            for y, x in visit:
                arr[y][x] = value
        if not is_Move:
            return cnt
        cnt += 1


if __name__ == "__main__":
    N, L, R = map(int, sys.stdin.readline().split())
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    print(move())
