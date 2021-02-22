from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(start):
    q = deque()
    result = list()
    q.append((start[0], start[1]))
    result.append((start[0], start[1]))
    maps[start[0]][start[1]] = 0

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if maps[nx][ny] == 1:
                    maps[nx][ny] = 0
                    q.append((nx, ny))
                    result.append((nx, ny))
    return result


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    island = []

    for i in range(n):
        for j in range(n):
            if maps[i][j] != 0:
                temp = bfs((i, j))
                island.append(temp)

    answer = 1e9
    for i in range(len(island)):
        for j in range(i + 1, len(island)):
            for x in range(len(island[i])):
                for y in range(len(island[j])):
                    answer = min(answer, abs(island[i][x][0] - island[j][y][0]) + abs(island[i][x][1] - island[j][y][1]))

    print(answer - 1)
