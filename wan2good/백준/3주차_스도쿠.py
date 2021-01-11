import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())
board=[];find=[]
for _ in range(9):
    board.append(list(MIS()))
for i in range(9):
    for j in range(9):
        if board[i][j]==0: find.append((i,j))

def remove(x,y):
    unique=[1,2,3,4,5,6,7,8,9]
    for i in range(9):
        if board[x][i] in unique: unique.remove(board[x][i])
    for i in range(9):
        if board[i][y] in unique: unique.remove(board[i][y])
    
    nx,ny=(x//3)*3,(y//3)*3
    for i in range(nx,nx+3):
        for j in range(ny,ny+3):
            if board[i][j] in unique: unique.remove(board[i][j])

    return unique

def dfs(idx):
    if idx==len(find): 
        for row in board:
            for col in row:
                print(col,end=' ')
            print()
        sys.exit()
    x,y=find[idx]
    uniqe=remove(x,y)
    for num in uniqe:
        board[x][y]=num
        dfs(idx+1)
        board[x][y]=0

dfs(0)