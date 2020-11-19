from collections import deque
from itertools import combinations
n,m,g,r=map(int,input().split())
board=[list(map(int,input().split())) for _ in range(n)]
dx=[-1,0,1,0];dy=[0,-1,0,1]
energy=[]
for i in range(n):
    for j in range(m):
        if board[i][j]==2:energy.append((i,j))

result=-2e10
def bfs():
    flower=0;q=deque()
    spread=[[[0,0] for _ in range(m)] for _ in range(n)]
    for i in r_list:
        x,y=energy[i]
        spread[x][y][1]=7 #red
        q.append((x,y))
    for i in g_list:
        x,y=energy[i]
        spread[x][y][1]=8 #green
        q.append((x,y))

    while q:
        x,y=q.popleft()
        if spread[x][y][1]==9: continue #flower
        for i in range(4):
            nx=x+dx[i];ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m and board[nx][ny]!=0:
                if spread[nx][ny][1]==0: # 호수
                    spread[nx][ny][0],spread[nx][ny][1] = spread[x][y][0]+1,spread[x][y][1]
                    q.append((nx,ny))
                elif spread[nx][ny][1]==7:
                    if spread[x][y][1]==8 and spread[x][y][0]+1==spread[nx][ny][0]: # 초록 배양액이 퍼졌을 때 시간이 같다면
                        spread[nx][ny][1]=9;flower+=1
                elif spread[nx][ny][1]==8:
                    if spread[x][y][1]==7 and spread[x][y][0]+1==spread[nx][ny][0]: # 빨간 배양액이 퍼졌을 때 시간이 같다면
                        spread[nx][ny][1]=9;flower+=1
    return flower

for a in combinations(range(len(energy)),r+g):
    for b in combinations(range(r+g),r):
        r_list=[];g_list=[]
        for i in range(r+g):
            if i in b: r_list.append(a[i])
            else:g_list.append(a[i])
        result=max(result,bfs())
print(result)
