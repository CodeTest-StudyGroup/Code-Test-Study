import copy

maze = [list(input()) for _ in range(8)]
maze[0][7] = "E"
maze[7][0] = "J"

# 8방향 + 가만히 있는 경우
dx = [-1, 1, 0, 0, 1, 1, -1, -1, 0]
dy = [0, 0, -1, 1, 1, -1, 1, -1, 0]

# 벽을 1칸씩 내림.
def move(a):
    maze2 = copy.deepcopy(a)
    for i in range(7, -1, -1):
        for j in range(8):
            if a[i][j] == "#":
                maze2[i][j] = "."
                if i < 7:
                    maze2[i+1][j] = "#"
    return maze2

# 욱제가 있는지 확인
def count_J(a):
    cnt = 0    
    for i in range(8):
        for j in range(8):
            if a[i][j] == "J":
                cnt += 1

    return cnt                

def bfs(a, b, c):

    for i in range(9):
        nx = a + dx[i]
        ny = b + dy[i]

        if nx < 0 or nx > 7 or ny < 0 or ny > 7:
            continue
        
        if c[nx][ny] == "E":
            print(1)
            exit(0)

        if c[nx][ny] == ".":
            c[nx][ny] = "J"


while 1:
    m = copy.deepcopy(maze)
    for i in range(8):
        for j in range(8):
            if maze[i][j] == "J":
                bfs(i, j, m)
    maze = copy.deepcopy(m) # m에서 이동시키고 다시 maze로 옮긴다.
    maze = move(maze)
    if count_J(maze) == 0:
        print(0)
        break