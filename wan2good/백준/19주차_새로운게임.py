import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())
dx=[0,0,-1,1];dy=[1,-1,0,0]

n,k=MIS();board=[]
for _ in range(n):
    board.append(list(MIS()))
chess_board=[[[] for _ in range(n)] for _ in range(n)]
chess=[0 for _ in range(k)]

for i in range(k):
    x,y,z=MIS()
    chess_board[x-1][y-1].append(i)
    chess[i]=[x-1,y-1,z-1]

def solve(idx):
    x,y,z=chess[idx]
    if idx!=chess_board[x][y][0]:
        return False

    nx,ny=x+dx[z],y+dy[z]
    if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
        if z==0: nz=1
        elif z==1: nz=0
        elif z==2: nz=3
        elif z==3: nz=2

        chess[idx][2]=nz
        nx=x+dx[nz]
        ny=y+dy[nz]
        if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
            return False

    chess_set=[]
    chess_set.extend(chess_board[x][y])
    chess_board[x][y]=[]

    if board[nx][ny]==1:
        chess_set=chess_set[::-1]

    for i in chess_set:
        chess_board[nx][ny].append(i)
        chess[i][0]=nx
        chess[i][1]=ny

    if len(chess_board[nx][ny])>=4: return True
    return False

turn=1
while turn<1001:
    for i in range(k):
        result=solve(i)
        if result:
            print(turn)
            sys.exit()
    turn+=1
print(-1)