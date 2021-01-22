from collections import deque
import sys

# 홀수 줄 왼쪽 위, 왼쪽 아래, 왼쪽, 오른쪽 위, 오른쪽 아래, 오른쪽
odd_dx = [-1, 1, 0, -1, 1, 0]
odd_dy = [0, 0, -1, 1, 1, 1]
# 짝수 줄 왼쪽 위, 왼쪽 아래, 왼쪽, 오른쪽 위, 오른쪽 아래, 오른쪽
even_dx = [-1, 1, 0, -1, 1, 0]
even_dy = [-1, -1, -1, 0, 0, 1]


def bfs():
    q = deque()
    q.append((0, 0))
    d[0][0] = 1
    while q:
        x, y = q.popleft()
        if x % 2 == 0:
            dx, dy = even_dx, even_dy
        else:
            dx, dy = odd_dx, odd_dy
        for i in range(6):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if i <= 2:
                    if tile[x][y][0] == tile[nx][ny][1] and d[nx][ny] == 0:
                        d[nx][ny] = d[x][y] + 1
                        move[nx][ny] = [x, y]
                        q.append((nx, ny))
                else:
                    if tile[x][y][1] == tile[nx][ny][0] and d[nx][ny] == 0:
                        d[nx][ny] = d[x][y] + 1
                        move[nx][ny] = [x, y]
                        q.append((nx, ny))


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    tile = [[[[] for _ in range(2)] for _ in range(n)] for _ in range(n)]
    d = [[0] * n for _ in range(n)]
    move = [[[[] for _ in range(2)] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        if i % 2 == 0:
            for j in range(n):
                x, y = map(int, sys.stdin.readline().split())  # 홀수 줄
                tile[i][j] = [x, y]
        else:
            for j in range(n - 1):
                x, y = map(int, sys.stdin.readline().split())  # 짝수 줄
                tile[i][j] = [x, y]

    if n == 1:
        print(1)
        print(1)
    else:
        # 타일 번호 저장 배열
        number = [[0] * n for _ in range(n)]
        num = 1
        for i in range(n):
            if i % 2 == 0:
                for j in range(n):
                    number[i][j] = num
                    num += 1
            else:
                for j in range(n - 1):
                    number[i][j] = num
                    num += 1

        # 가장 짧은 경로의 길와 경로 찾기
        bfs()
        distance = None
        path = []
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if d[i][j] != 0:  # 가장 먼저 거리 정보가 나오는 곳이 번호가 가장 큰 타일 혹은 도착 지점이다.
                    print(d[i][j])
                    path.append(number[i][j])
                    q = deque()
                    q.append(move[i][j])
                    while q:
                        x, y = q.popleft()
                        path.append(number[x][y])
                        nx, ny = move[x][y]
                        if nx == 0 and ny == 0:
                            path.append(number[nx][ny])
                            break
                        q.append((nx, ny))
                    path.reverse()
                    print(" ".join(map(str, path)))
                    sys.exit(0)