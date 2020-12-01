from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def outer(r, c, visited):
    q = deque()
    q.append((r, c))

    while q:
        x, y = q.popleft()
        visited.add((x, y))
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if maps[nx][ny] != 1 and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    q.append((nx, ny))


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    t = 0
    while True:
        # 외부 공기 구별
        visited = set()
        for i in range(n):
            if maps[i][0] != 1:
                outer(i, 0, visited)
        for i in range(n):
            if maps[i][m - 1] != 1:
                outer(i, m - 1, visited)
        for i in range(m):
            if maps[0][i] != 1:
                outer(0, i, visited)
        for i in range(m):
            if maps[n - 1][i] != 1:
                outer(n - 1, i, visited)
        for i, j in visited:
            maps[i][j] = 2

        cnt = 0  # 치즈 개수
        for i in range(n):
            for j in range(m):
                # 가장 자리 제외
                if (i == 0 and j == 0) or (i == 0 and j == m - 1) or (i == n - 1 and j == 0) or (
                        i == n - 1 and j == m - 1) or maps[i][j] != 1:
                    continue
                cnt += 1
                outer_cnt = 0
                # 외부 공기 개수 파악(상, 하, 좌, 우)
                if i - 1 >= 0 and maps[i - 1][j] == 2:  # 상
                    outer_cnt += 1
                if i + 1 < n and maps[i + 1][j] == 2:  # 하
                    outer_cnt += 1
                if j - 1 >= 0 and maps[i][j - 1] == 2:  # 좌
                    outer_cnt += 1
                if j + 1 < m and maps[i][j + 1] == 2:  # 우
                    outer_cnt += 1
                if outer_cnt >= 2:
                    maps[i][j] = 0  # 치즈 제거
        if cnt == 0:
            break
        t += 1

    print(t)
