import sys
from collections import deque

n, t = map(int, sys.stdin.readline().split())

h_set = set()
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    h_set.add((x,y))


def bfs(h_set):
    dx, dy = [-2, -1, 0, 1, 2], [-2, -1, 0, 1, 2]
    queue = deque([[0,0,0]])  # 행, 열, 이동휫수
    while queue:
        x, y, cnt = queue.popleft()
        if y == t:
            return cnt
        for i in range(5):
            for j in range(5):
                nx, ny = x + dx[i], y + dy[j]
                if (nx,ny) in h_set:
                    queue.append([nx,ny, cnt+1])
                    h_set.remove((nx,ny))
    return -1


print(bfs(h_set))