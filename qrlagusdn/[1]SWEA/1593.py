#탈주범 검거

#DFS로 구현.
#예외 처리 못한듯.

tunnel = list()
#중복방문 허용, but 바로 전 값만 아니면됨.
def upCheck(dir, newy,newx):
    if dir ==0 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 2 or MAP[newy][newx] == 5 or MAP[newy][newx] == 6) and tunnel[newy][newx] == 0 : return True
    return False
def downCheck(dir,newy,newx):
    if dir == 1 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 2 or MAP[newy][newx] == 4 or MAP[newy][newx] == 7) and tunnel[newy][newx] == 0: return True
    return False
def leftCheck(dir,newy,newx):
    if dir == 2 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 3 or MAP[newy][newx] == 4 or MAP[newy][newx] == 5) and tunnel[newy][newx] == 0: return True
    return False
def rightCheck(dir,newy,newx):
    if dir == 3 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 3 or MAP[newy][newx] == 6 or MAP[newy][newx] == 7) and tunnel[newy][newx] == 0: return True
    return False
    


def dfs(cnt, y,x):
    global tunnel
    if cnt > L: #Basis case
        return
    
    tunnel[y][x] = 1
    
    if MAP[y][x] == 1:#사방
        for dir in range(0,4):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir, newy,newx): #상
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif downCheck(dir,newy,newx):#하
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif leftCheck(dir,newy,newx):#좌
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif rightCheck(dir,newy,newx):#우
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                

    elif MAP[y][x] == 2:#상 하
        for dir in range(0,2):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir,newy,newx): #상
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif downCheck(dir,newy,newx):#하
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
            

    elif MAP[y][x] == 3:#좌 우
        for dir in range(2,4):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if leftCheck(dir,newy,newx):#좌
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif rightCheck(dir,newy,newx):#우
                    dfs(cnt+1,y + dy[dir],x + dx[dir])

    elif MAP[y][x] == 4:#상 우
        flag = 0
        for _ in range(2):
            if flag ==0:
                dir = 0 #상
            elif flag == 1:
                dir = 3 #우
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir,newy,newx): #상 
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif rightCheck(dir,newy,newx):#우
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
            flag = 1
            

    elif MAP[y][x] == 5:#하 우
        flag = 0
        for _ in range(2):
            if flag ==0:
                dir = 1 #하
            elif flag == 1:
                dir = 3 #우
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if downCheck(dir,newy,newx):#하
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif rightCheck(dir,newy,newx):#우
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
            flag = 1

    elif MAP[y][x] == 6:#하 좌
        flag = 0
        for _ in range(2):
            if flag ==0:
                dir = 1 #하
            elif flag == 1:
                dir = 2 #좌
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if downCheck(dir,newy,newx):#하
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif leftCheck(dir,newy,newx):#좌
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
            flag = 1

    elif MAP[y][x] == 7:#상 좌
        flag = 0
        for _ in range(2):
            if flag ==0:
                dir = 0 #상
            elif flag == 1:
                dir = 2 #좌
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir,newy,newx): #상 
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
                elif leftCheck(dir,newy,newx):#좌
                    dfs(cnt+1,y + dy[dir],x + dx[dir])
            flag = 1

if __name__ == "__main__":
    T = int(input())
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    
    for TC in range(1,T+1):
        N,M,R,C,L = map(int,input().split())
        MAP = list()
        for i in range(N):#맵 입력
            MAP.append(list(map(int,input().split())))
        tunnel = [[0 for _ in range(M)]for _ in range(N)]
        cnt = 0
        if L == 1:
            cnt = 1
        else:    
            dfs(1, R,C)

        for i in range(0,N):
            for j in range(0,M):
                if tunnel[i][j] == 1:
                    cnt += 1
        print("#%d %d" %(TC,cnt))