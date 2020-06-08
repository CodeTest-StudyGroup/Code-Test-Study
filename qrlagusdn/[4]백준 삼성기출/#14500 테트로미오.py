#14500 테트로미오

#아,,, N*M입니다. .ㅎㅎ N * N 이 아니라..

# ㅗ 같은 경우는 dfs로 탐색이 안된다.
#따라서 dfs 로 다른 경우들 탐색하고, ㅗ를 따로 함수 만들어서 탐색 해주었다.

import sys

MAX = -999999

def dfs(y,x,cnt,sum,visited):
    global MAX
    if cnt == 4:
        MAX = max(MAX,sum)
        return

    for dir in range(4):
        newy = y + dy[dir]
        newx = x + dx[dir]
        if 0<= newy <N and 0<=newx<M and visited[newy][newx] == 0:
            sum += MAP[newy][newx]
            visited[newy][newx] = 1
            dfs(newy, newx, cnt+1,sum,visited)
            sum -= MAP[newy][newx]
            visited[newy][newx] = 0

def dfs_except(y,x):#ㅗ ㅏ ㅜ ㅓ
    global MAX
    if 0<= y < N-1 and 0<= x < M-2: #ㅜ
        sum = MAP[y][x] + MAP[y][x+1] + MAP[y][x+2] + MAP[y+1][x+1]
        MAX = max(MAX,sum)
    if 0<= y < N-2 and 1<= x < M: #ㅓ
        sum = MAP[y][x] + MAP[y+1][x] + MAP[y+2][x] + MAP[y+1][x-1]
        MAX = max(MAX,sum)
    if 1<= y <N and 0<=x <M-2:#ㅗ
        sum = MAP[y][x] + MAP[y][x+1] + MAP[y][x+2] + MAP[y-1][x+1]
        MAX = max(MAX,sum)
    if 0<= y < N-2 and 0<= x <M-1: #ㅏ
        sum = MAP[y][x] + MAP[y+1][x] + MAP[y+2][x] + MAP[y+1][x+1]
        MAX = max(MAX,sum)

if __name__ == "__main__":
    N, M = map(int,sys.stdin.readline().split())
    MAP = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]

    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    visited = [[0 for _ in range(M)]for _ in range(N)]
    for i in range(0,N):
        for j in range(0,M):
            visited[i][j] = 1
            dfs(i,j,1,MAP[i][j], visited)
            dfs_except(i,j)
            visited[i][j] = 0
    print(MAX)
