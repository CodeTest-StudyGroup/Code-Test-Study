from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

maze = [list(map(int, input().split())) for _ in range(n)]
visit = [[0] * m for _ in range(n)]


def bfs(a, b):
    q = deque()
    q.append((a, b))
    visit[a][b] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            
            if maze[nx][ny] == 1 and not visit[nx][ny]:
                maze[nx][ny] = maze[x][y] + 1
                visit[nx][ny] = 1
                q.append((nx, ny))

start_x = 0
start_y = 0
for i in range(n):
    for j in range(m):
        if maze[i][j] == 2:
            start_x = i
            start_y = j
            break
maze[start_x][start_y] = 0            
bfs(start_x, start_y)

for i in range(n):
    for j in range(m):
        if maze[i][j] == 1 and not visit[i][j]:
            maze[i][j] = -1
for i in maze:
    print(*i)