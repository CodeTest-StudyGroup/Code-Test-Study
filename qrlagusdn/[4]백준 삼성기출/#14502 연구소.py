#14502 연구소

import copy

dy = [-1,1,0,0]
dx = [0,0,-1,1]
MAX = 0
MAP2 = list()
def virus(MAP2):
    queue = list()
    
    for y in range(0,N):
        for x in range(0,M):
            if MAP2[y][x] == 2:
                queue.append((y,x))

    while queue:
        pos = queue.pop(0)
        y = pos[0]
        x = pos[1]
        for dir in range(0,4):
            newy = y+dy[dir]
            newx = x+dx[dir]
            if 0<=newy<N and 0<=newx<M and MAP2[newy][newx] == 0:
                MAP2[newy][newx] = 2
                queue.append((newy,newx))
    

def dfs(MAP,cnt):
    global MAX
    if cnt == 3:
        #빈칸 check
        MAP2 = copy.deepcopy(MAP) #바이러스가 퍼질 새로운 맵 생성
        virus(MAP2)
        survive = 0
        for y in range(0,N):
            for x in range(0,M):
                if MAP2[y][x] == 0:
                    survive += 1
        if MAX < survive:
            MAX = survive
        return

    for row in range(0,N):
        for col in range(0,M):
            if MAP[row][col] == 0:
                MAP[row][col] = 1
                dfs(MAP,cnt+1)
                MAP[row][col] = 0

if __name__ == "__main__":
    N,M = map(int,input().split())

    MAP = [list(map(int,input().split())) for _ in range(N)]
    dfs(MAP,0)
    print(MAX)
