from collections import deque
import sys
sys.setrecursionlimit(10**8)

# 말처럼 이동
h_dx = [-1, -2, -2, -1, 1, 2, 2, 1]
h_dy = [-2, -1, 1, 2, 2, 1, -1, -2]

# 상, 하, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    q.append((0, 0, 0, k))

    while q:
        x, y, cnt, remain_k = q.popleft()
        if remain_k >= 1:
            # 말처럼 이동
            for i in range(8):
                nx, ny = x + h_dx[i], y + h_dy[i]
                if 0 <= nx < h and 0 <= ny < w and maps[nx][ny] == 0:
                    if visited[nx][ny] == -1 or visited[nx][ny] < remain_k - 1:
                        if nx == h - 1 and ny == w - 1:
                            return cnt + 1
                        visited[nx][ny] = remain_k - 1
                        q.append((nx, ny, cnt + 1, remain_k - 1))
        # 상, 하, 좌, 우 이동
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < h and 0 <= ny < w and maps[nx][ny] == 0:
                if visited[nx][ny] == -1 or visited[nx][ny] < remain_k:
                    if nx == h - 1 and ny == w - 1:
                        return cnt + 1
                    visited[nx][ny] = remain_k
                    q.append((nx, ny, cnt + 1, remain_k))
    return -1


if __name__ == "__main__":
    k = int(sys.stdin.readline())
    w, h = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    visited = [[-1] * w for _ in range(h)]

    if w == 1 and h == 1:
        print(0)
    else:
        print(bfs())