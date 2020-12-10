input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
m,n=MIS();board=[[1 for _ in range(m)] for _ in range(m)]
data=[0]*(2*m-1)
for _ in range(n):
    a,b,c=MIS()
    for i in range(a,a+b):
        data[i]+=1
    for i in range(a+b,len(data)):
        data[i]+=2
    
idx=0
for i in range(m-1,-1,-1):
    board[i][0]+=data[idx];idx+=1
for i in range(1,m):
    board[0][i]+=data[idx];idx+=1

for i in range(1,m):
    for j in range(1,m):
        board[i][j]=board[i-1][j]
for row in board:
    for col in row:
        print(col,end=' ')
    print()