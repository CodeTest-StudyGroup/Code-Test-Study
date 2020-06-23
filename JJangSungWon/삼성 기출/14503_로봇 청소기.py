# boj 14503
# blog : jjangsungwon.tistory.com

import sys
from collections import deque

# 북 동 남 서
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


# 방향 전환
def change(d):
    if d == 0:  # 북 -> 서
        return 3
    elif d == 1:  # 동 -> 북
        return 0
    elif d == 2:  # 남 -> 동
        return 1
    elif d == 3:  # 서 -> 동
        return 2


# 후진
def back(d):
    if d == 0:
        return 2
    elif d == 1:
        return 3
    elif d == 2:
        return 0
    elif d == 3:
        return 1


def bfs(row, col, d):
    cnt = 1  # 청소하는 칸의 개수
    arr[row][col] = 2
    q = deque([[row, col, d]])

    # 큐가 비어지면 종료
    while q:
        row, col, d = q.popleft()
        temp_d = d

        for i in range(4):
            temp_d = change(temp_d)
            new_row, new_col = row + dy[temp_d], col + dx[temp_d]

            # a
            if 0 <= new_row < N and 0 <= new_col < M and arr[new_row][new_col] == 0:
                cnt += 1
                arr[new_row][new_col] = 2
                q.append([new_row, new_col, temp_d])
                break

            # c
            elif i == 3:  # 갈 곳이 없었던 경우
                new_row, new_col = row + dy[back(d)], col + dx[back(d)]
                q.append([new_row, new_col, d])

                # d
                if arr[new_row][new_col] == 1:  # 뒤가 벽인 경우
                    return cnt


if __name__ == "__main__":
    N, M = map(int, input().split())
    r, c, d = map(int, input().split())

    # 지도
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    # 탐색
    print(bfs(r, c, d))
