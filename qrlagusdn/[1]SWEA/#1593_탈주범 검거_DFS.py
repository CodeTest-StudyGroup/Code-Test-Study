#탈주범 검거

#DFS로 구현.
#예외 처리 못한듯.

#visited 처리해보자
#MAP 값을 0 visiteㅇ로?
#BFS로 짜보자



'''
처음 접근 : 설마 터널 다 탐색해서 맵을 재구성해야하나? 라고 생각을했다.
즉, dfs 를 두번 사용해서 탐색해야한다고 생각했다. 그런데 시작점을 기준으로 터널을 탐색해도 된다는 생각에 터널의 종류에 따라 케이스를 나누어서 dfs를 구현하였다. 
그런데 dfs로 하다보니 예외 처리할 부분이 상당히 많았다. 
사실 bfs로 해도 예외 처리할 부분이 똑같은 것 같지만 잘 이해가 되지 않는다. 
BFS로 구현을 한번 해보긴 해야겠다.

내가 맨첨에 값이 잘 안나온 이유는 tunnel 이라는 방문할 수 있었던 곳을 체크하는 부분과, visited로 dfs 를 수행할때 방문한 곳은 중복 안되게 하는 리스트를 구분하지 못했다. visited를 만들어서 넣어주니 값이 잘 나왔다.

'''


tunnel = list()
#중복방문 허용, but 바로 전 값만 아니면됨.
def upCheck(dir, newy,newx):
    if dir == 0 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 2 or MAP[newy][newx] == 5 or MAP[newy][newx] == 6) and visited[newy][newx] == 0 : return True
    return False
def downCheck(dir,newy,newx):
    if dir == 1 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 2 or MAP[newy][newx] == 4 or MAP[newy][newx] == 7) and visited[newy][newx] == 0: return True
    return False
def leftCheck(dir,newy,newx):
    if dir == 2 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 3 or MAP[newy][newx] == 4 or MAP[newy][newx] == 5) and visited[newy][newx] == 0: return True
    return False
def rightCheck(dir,newy,newx):
    if dir == 3 and (MAP[newy][newx] == 1 or MAP[newy][newx] == 3 or MAP[newy][newx] == 6 or MAP[newy][newx] == 7) and visited[newy][newx] == 0: return True
    return False
    


def dfs(cnt, y,x, visited):
    global tunnel
    if cnt == L: #Basis case
        return
    
    tunnel[y][x] = 1
    visited[y][x] = 1
    
    if MAP[y][x] == 1:#사방
        for dir in range(0,4):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir, newy,newx): #상
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif downCheck(dir,newy,newx):#하
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif leftCheck(dir,newy,newx):#좌
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif rightCheck(dir,newy,newx):#우
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                

    elif MAP[y][x] == 2:#상 하
        for dir in range(0,2):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if upCheck(dir,newy,newx): #상
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif downCheck(dir,newy,newx):#하
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
            

    elif MAP[y][x] == 3:#좌 우
        for dir in range(2,4):
            newy = y + dy[dir]
            newx = x + dx[dir]
            if 0<= newx < M and 0<= newy <N:
                if leftCheck(dir,newy,newx):#좌
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif rightCheck(dir,newy,newx):#우
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0

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
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif rightCheck(dir,newy,newx):#우
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
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
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif rightCheck(dir,newy,newx):#우
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
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
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif leftCheck(dir,newy,newx):#좌
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
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
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
                elif leftCheck(dir,newy,newx):#좌
                    visited[newy][newx] = 1
                    tunnel[newy][newx] = 1
                    dfs(cnt+1,y + dy[dir],x + dx[dir], visited)
                    visited[newy][newx] = 0
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
        visited = [[0 for _ in range(M)]for _ in range(N)]
        cnt = 0
        if L == 1:
            cnt = 1
        else:    
            dfs(1, R,C, visited)

        for i in range(0,N):
            for j in range(0,M):
                if tunnel[i][j] == 1:
                    cnt += 1
        print("#%d %d" %(TC,cnt))