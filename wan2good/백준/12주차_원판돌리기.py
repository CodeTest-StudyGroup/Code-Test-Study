from collections import deque
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,m,t=MIS();board=[[]];order=[]
dx=[-1,0,1,0];dy=[0,-1,0,1]
for _ in range(n):
    board.append(deque(MIS()))
for _ in range(t):
    order.append(list(MIS()))

for o_x,d,k in order:
    idx=0
    if d==0: # 시계 방향
        for row in range(o_x,len(board),o_x):
            board[row].rotate(k);idx=row
            
    else:    # 반시계 방향
        for row in range(o_x,len(board),o_x):
            board[row].rotate(-k);idx=row

    pos=[];value=0;cnt=0
    for x in range(1,len(board)):
        for y in range(len(board[x])):
            if board[x][y]!=0:
                value+=board[x][y];cnt+=1
                for i in range(4):
                    nx=x+dx[i]
                    ny=(y+dy[i])%m
                    if 1<=nx<=n and 0<=ny<m and board[nx][ny]==board[x][y]:
                        pos.append((nx,ny));pos.append((x,y))
    if cnt!=0: avg=value/cnt
    else: avg=0
    pos=set(pos)
    if pos:
        for x,y in pos:
            board[x][y]=0
    else:
        for i in range(1,len(board)):
            for j in range(len(board[i])):
                if board[i][j]!=0:
                    if board[i][j]<avg: board[i][j]+=1
                    elif board[i][j]>avg: board[i][j]-=1

result=0
for i in range(1,len(board)):
    for j in range(len(board[i])):
        if board[i][j]!=0: result+=board[i][j]
print(result)