from collections import deque
import sys


dx = [None, 0, 0, 1, -1]
dy = [None, 1, -1, 0, 0]
INF = 1e9


def direction_change_count(pre, post):
    if pre == post:
        return 0
    elif (pre == 1 and post == 2) or (pre == 2 and post == 1):
        return 2
    elif (pre == 3 and post == 4) or (pre == 4 and post == 3):
        return 2
    else:
        return 1


def bfs(start):
    q = deque()
    start_x, start_y, start_dir = start[0], start[1], start[2]  # x, y, 방향
    q.append((start_x, start_y, start_dir, 0))  # x, y, 방향, 명령 횟수
    visited = set()
    while q:
        x, y, d, cnt = q.popleft()
        if x == end[0] and y == end[1]:
            return cnt + direction_change_count(d, end[2])
        for i in range(1, 4):
            nx, ny = x + dx[d] * i, y + dy[d] * i
            if 0 <= nx < m and 0 <= ny < n and maps[nx][ny] == 0:
                if (nx, ny, d, cnt + 1) not in visited:
                    q.append((nx, ny, d, cnt + 1))
                    visited.add((nx, ny, d, cnt + 1))
            else:
                break
        for i in range(1, 5):
            if i != d and (x, y, i, cnt + 1) not in visited:
                q.append((x, y, i, cnt + direction_change_count(d, i)))
                visited.add((x, y, i, cnt + direction_change_count(d, i)))


if __name__ == "__main__":
    m, n = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
    start = list(map(int, sys.stdin.readline().split()))  # 출발 지점
    end = list(map(int, sys.stdin.readline().split()))  # 도착 지점
    start[0], start[1] = start[0] - 1, start[1] - 1
    end[0], end[1] = end[0] - 1, end[1] - 1

    answer = bfs(start)
    print(answer)