from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    q.append((1, 1))
    visited = {(1, 1)}
    count = {(1, 1)}
    switch[1][1] = True

    while q:
        x, y = q.popleft()
        # 불을 켤 수 있는 스위치가 있는지 확인
        if len(maps[x][y]) == 0:
            pass
        else:
            for i in range(len(maps[x][y])):
                switch[maps[x][y][i][0]][maps[x][y][i][1]] = True  # 스위치 켜기
                count.add((maps[x][y][i][0], maps[x][y][i][1]))
                if (maps[x][y][i][0], maps[x][y][i][1]) not in visited:
                    for j in range(4):
                        nx, ny = maps[x][y][i][0] + dx[j], maps[x][y][i][1] + dy[j]
                        if 1 <= nx <= n and 1 <= ny <= n:
                            if (nx, ny) in visited:
                                q.append((nx, ny))
                                visited.add((nx, ny))
                                break
        # 상, 하, 좌, 우 확인
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 1 <= nx <= n and 1 <= ny <= n:
                if switch[nx][ny] and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    q.append((nx, ny))

    return len(count)


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
    switch = [[False] * (n + 1) for _ in range(n + 1)]
    for _ in range(m):
        x, y, a, b = map(int, sys.stdin.readline().split())
        maps[x][y].append([a, b])

    print(bfs())
