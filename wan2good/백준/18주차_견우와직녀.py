from collections import deque

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,m=MIS();board=[]
for _ in range(n):
    board.append(list(MIS()))

def bfs():
    global result
    q=deque();q.append((0,0,0,0))
    visited=[[False for _ in range(n)] for _ in range(n)]
    visited[0][0]=True
    while q:
        x,y,cnt,flag=q.popleft()
        if x==n-1 and y==n-1:
            result=min(result,cnt);break
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<n:
                if board[nx][ny]==-1: continue
                if board[nx][ny]==1 and not visited[nx][ny]:
                    visited[nx][ny]=True
                    q.append((nx,ny,cnt+1,0))
                elif board[nx][ny]>=2 and not visited[nx][ny] and not flag:
                    if ((cnt+1)%board[nx][ny])==0:
                        visited[nx][ny]=1
                        q.append((nx,ny,cnt+1,1))
                    else:
                        q.append((x,y,cnt+1,0))

bridges=[]
dx=[-1,0,1,0];dy=[0,-1,0,1]
for i in range(n):
    for j in range(n):
        row,col=0,0
        if board[i][j]==0:
            bridges.append((i,j))
            for x in range(1,4,2):
                nx,ny=i+dx[x],j+dy[x]
                if 0<=nx<n and 0<=ny<n:
                    if board[nx][ny]==0 or board[nx][ny]==-1 or board[nx][ny]>=2:
                        row+=1
            for x in range(0,3,2):
                nx,ny=i+dx[x],j+dy[x]
                if 0<=nx<n and 0<=ny<n:
                    if board[nx][ny]==0 or board[nx][ny]==-1 or board[nx][ny]>=2:
                        col+=1
        if row>=1 and col>=1: 
            board[i][j]=-1
            bridges.remove((i,j))

result=2e10
for i in range(len(bridges)):
    x,y=bridges[i]
    board[x][y]=m
    bfs()
    board[x][y]=0
print(result)