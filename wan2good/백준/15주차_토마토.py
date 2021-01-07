import sys
from collections import deque
from copy import deepcopy

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
m,n,h=MIS();board=[];tomato=[]
dz=[-1,1];dx=[-1,0,1,0];dy=[0,-1,0,1]

for _ in range(h):
    floor=[]
    for _ in range(n):
        floor.append(list(MIS()))
    board.append(floor)

cnt=0
for z in range(h):
    for i in range(n):
        for j in range(m):
            if board[z][i][j]==1: tomato.append((z,i,j))
            elif board[z][i][j]==0: cnt+=1
if cnt==0: print(0);sys.exit()

result=0
while True:
    q=deque(tomato);tmp=[]
    if len(q)==0: break
    while q:
        z,x,y=q.popleft()
        for i in range(2):
            nz=z+dz[i]
            if 0<=nz<h:
                if board[nz][x][y]==0: board[nz][x][y]=1;tmp.append((nz,x,y))
        for j in range(4):
            nx,ny=x+dx[j],y+dy[j]
            if 0<=nx<n and 0<=ny<m:
                if board[z][nx][ny]==0: board[z][nx][ny]=1;tmp.append((z,nx,ny))
    result+=1;tomato=deepcopy(tmp)

for z in range(h):
    for i in range(n):
        for j in range(m):
            if board[z][i][j]==0: print(-1);sys.exit()
print(result-1)