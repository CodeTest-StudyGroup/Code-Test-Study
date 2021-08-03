import sys
from collections import deque

r, c = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]

curr_j = []
fire_loc = []

for i in range(r):
    for j in range(c):
        if board[i][j] == 'J':
            curr_j.append([i,j, 0])   # 지훈의 위치 행,열 , 현재 시간
        elif board[i][j] == 'F':
            fire_loc.append([i,j])


def bfs(board, curr_j, fire_loc):
    dx, dy = [-1,1,0,0], [0,0,-1,1]

    f_queue = deque(fire_loc)
    j_queue = deque(curr_j)
    nf_queue, nj_queue = deque(), deque()

    while f_queue or j_queue:
        while f_queue:
            fx, fy = f_queue.popleft()
            for i in range(4):
                nfx, nfy = fx + dx[i], fy + dy[i]
                if 0 <= nfx < r and 0 <= nfy < c and (board[nfx][nfy] == '.' or board[nfx][nfy] == 'J'):
                    board[nfx][nfy] = 'F'
                    nf_queue.append([nfx, nfy])

        while j_queue:
            jx, jy, time = j_queue.popleft()
            if jx == 0 or jy == 0 or jx == r-1 or jy == c-1:
                return time+1
            for j in range(4):
                njx, njy = jx + dx[j], jy + dy[j]
                if 0 <= njx < r and 0 <= njy < c and board[njx][njy] == '.':
                    board[njx][njy] = 'J'
                    nj_queue.append([njx, njy, time+1])

        if not nj_queue:        # 다음에 갈 곳이 없을 때
            return "IMPOSSIBLE"

        f_queue = nf_queue
        nf_queue = deque()

        j_queue = nj_queue
        nj_queue = deque()


print(bfs(board, curr_j, fire_loc))