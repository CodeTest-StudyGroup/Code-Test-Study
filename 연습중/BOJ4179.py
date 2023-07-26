R, C = map(int, input().split())
maze = []
for _ in range(R):
    r = list(input().strip())
    maze.append(r)

def solution(R, C, maze):
    fire = []  
    jihun = [] 
    ji_cnt = 1
    visit = set()
    move = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for i in range(R):
        for j in range(C):
            if maze[i][j] == 'F':
                fire.append((i, j))
                visit.add((i, j))
            elif maze[i][j] == 'J':
                jihun.append((i, j, 0))
                visit.add((i, j))  

    while ji_cnt > 0:
        fire_cnt = len(fire)
        for _ in range(fire_cnt):
            x, y = fire.pop(0)
            for dx, dy in move:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] != '#':
                    if (nx, ny) not in visit:
                        maze[nx][ny] = 'F'
                        fire.append((nx, ny))
                        visit.add((nx, ny))
        
        cnt = 0
        for _ in range(ji_cnt):
            x, y, time = jihun.pop(0)
            if x == 0 or x == R - 1 or y == 0 or y == C - 1:
                return time + 1
            for dx, dy in move:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] == '.' and (nx, ny):
                    if (nx, ny) not in visit:
                        jihun.append((nx, ny, time + 1))
                        visit.add((nx, ny))
                        cnt += 1

        ji_cnt = cnt

    return "IMPOSSIBLE"

print(solution(R, C, maze))