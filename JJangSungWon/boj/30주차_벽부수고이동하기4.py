from collections import defaultdict, deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def move(array, visited, x, y, cnt):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:  # map을 벗어나는지 확인
            if visited[nx][ny] is False and array[nx][ny] == 0:  # 방문 x & 이동할 수 있는 곳
                visited[nx][ny] = True
                cnt = move(array, visited, nx, ny, cnt + 1)
    return cnt


# 해당 위치와 인접한 0의 개수 리턴
def bfs(x, y):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:  # 범위 확인
                if maps[nx][ny] == 0 and visited[nx][ny] is False:
                    visited[nx][ny] = True
                    zero_groups[nx][ny] = index
                    cnt += 1
                    q.append((nx, ny))
    return cnt


def move(x, y):
    visited_set = set()  # 방문한 0의 그룹 저장
    q = deque()
    q.append((x, y))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:  # 범위 확인
                if maps[nx][ny] == 0 and zero_groups[nx][ny] not in visited_set:
                    visited_set.add(zero_groups[nx][ny])
    return visited_set


if __name__ == "__main__":
    # input
    n, m = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().strip())) for _ in range(n)]
    zero_groups = [[0] * m for _ in range(n)]
    result = [[set()] * m for _ in range(n)]

    # 0 그룹화
    zero_groups_dict = defaultdict(int)
    visited = [[False] * m for _ in range(n)]
    index = 1
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 0 and visited[i][j] is False:
                zero_groups[i][j] = index
                zero_groups_dict[index] = bfs(i, j)
                index += 1

    # 현재 위치에서 이동할 수 있는 공간 확인
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 0:
                result[i][j] = 0
            else:
                temp = move(i, j)
                cnt = 0
                for key in temp:
                    cnt += zero_groups_dict[key]
                result[i][j] = (cnt + 1) % 10

    for i in range(n):
        print("".join(map(str, result[i])))