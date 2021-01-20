from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = 1e9
answer = INF


def bfs():
    global answer
    q = deque()
    q.append((0, 0, 0, False, False))
    d = dict()
    d[(0, 0, False)] = 0

    while q:
        x, y, cnt, flag, cross = q.popleft()
        if cnt > answer:
            continue
        if x == n - 1 and y == n - 1:
            answer = min(answer, cnt)
            continue
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if maps[nx][ny] != 0:
                    if maps[nx][ny] == 1:
                        if cnt + 1 < d.get((nx, ny, flag), INF):
                            q.append((nx, ny, cnt + 1, flag, False))
                            d[(nx, ny, flag)] = cnt + 1
                    elif not cross:
                        if (cnt + 1) % maps[nx][ny] == 0:
                            t = cnt + 1
                        else:
                            t = cnt + (maps[nx][ny] - cnt % maps[nx][ny])
                        if t < d.get((nx, ny, flag), INF):
                            q.append((nx, ny, t, flag, True))
                            d[(nx, ny, flag)] = t
                else:
                    if not flag and not cross:
                        # (상, 우) 확인
                        temp = True
                        if nx - 1 >= 0 and ny + 1 < n:
                            if maps[nx - 1][ny] == 0 and maps[nx][ny + 1] == 0:
                                temp = False
                        # (상, 좌) 확인
                        if nx - 1 >= 0 and ny - 1 >= 0:
                            if maps[nx - 1][ny] == 0 and maps[nx][ny - 1] == 0:
                                temp = False
                        # (하, 우) 확인
                        if nx + 1 < n and ny + 1 < n:
                            if maps[nx + 1][ny] == 0 and maps[nx][ny + 1] == 0:
                                temp = False
                        # (하, 좌) 확인
                        if nx + 1 < n and ny - 1 >= 0:
                            if maps[nx + 1][ny] == 0 and maps[nx][ny - 1] == 0:
                                temp = False
                        if temp:
                            if (cnt + 1) % m == 0:
                                t = cnt + 1
                            else:
                                t = cnt + (m - cnt % m)
                            if t < d.get((nx, ny, True), INF):
                                q.append((nx, ny, t, True, True))
                                d[(nx, ny, True)] = t


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    bfs()
    print(answer)
