from collections import deque

input==__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
k=int(input().rstrip());w,h=MIS();board=[]
for _ in range(h):
    board.append(list(MIS()))
q=deque();q.append((0,0,0))
dx=[-1,0,1,0];dy=[0,-1,0,1]
h_dx=[-2,-1,1,2,2,1,-1,-2];h_dy=[-1,-2,-2,-1,1,2,2,1]
visited=[[[0 for _ in range(k+1)] for _ in range(w)] for _ in range(h)]
result=2e10;visited[0][0][0]=0

def bfs():
    while q:
        x,y,tmpk=q.popleft()
        if x==h-1 and y==w-1: print(visited[x][y][tmpk]);return
        if tmpk<k:
            for i in range(8):
                nx,ny=x+h_dx[i],y+h_dy[i]
                if 0<=nx<h and 0<=ny<w and board[nx][ny]!=1 and not visited[nx][ny][tmpk+1]:
                    q.append((nx,ny,tmpk+1));visited[nx][ny][tmpk+1]=visited[x][y][tmpk]+1
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<h and 0<=ny<w and board[nx][ny]!=1 and not visited[nx][ny][tmpk]:
                q.append((nx,ny,tmpk));visited[nx][ny][tmpk]=visited[x][y][tmpk]+1
    print(-1)

bfs()
