from collections import deque
import sys

input = sys.stdin.readline
n, T = map(int, input().split())

cor = set()
for _ in range(n):
    x, y = map(int, input().split())
    cor.add((x, y))

dx = [-2, -1, 0, 1, 2]
dy = [-2, -1, 0, 1, 2]

q = deque()
q.append([0, 0, 0])

while q:
    x, y, cnt = q.popleft()
    if y == T:
        print(cnt)
        exit(0)    
    for i in range(5):
        for j in range(5):
            nx = x + dx[i]
            ny = y + dy[j]
            if (nx, ny) in cor:
                q.append([nx, ny, cnt + 1])
                cor.remove((nx, ny))
print(-1)