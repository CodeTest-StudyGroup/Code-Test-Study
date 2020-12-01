from collections import deque
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,m=MIS();board=[];cheese=[];dx=[-1,0,1,0];dy=[0,-1,0,1]
for _ in range(n):
    board.append(list(MIS()))

def find_out_air(x,y):
    q=deque()
    q.append((x,y))
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<m and board[nx][ny]==0:
                board[nx][ny]=9;q.append((nx,ny))

time=0;find_out_air(0,0)
while True:
    melted=[];flag=False
    for i in range(n):
        for j in range(m):
            cnt=0
            if board[i][j]==1:
                flag=True
                x,y=i,j
                for idx in range(4):
                    nx,ny=x+dx[idx],y+dy[idx]
                    if 0<=nx<n and 0<=ny<m and board[nx][ny]==9: cnt+=1
                if cnt>=2: melted.append((x,y))
    for x,y in melted:
        board[x][y]=9
        find_out_air(x,y)
    if flag: time+=1
    else: print(time);break