n=int(input());board=[]
MIS=lambda:map(int,input().split())
for _ in range(n):
    board.append(list(MIS()))
per=[1,1,2,2,7,7,10,10,5]
dx=[[-1,1,-2,2,-1,1,-1,1,0,0],[0,0,1,1,1,1,2,2,3,2],[-1,1,-2,2,-1,1,-1,1,0,0],[0,0,-1,-1,-1,-1,-2,-2,-3,-2]]
dy=[[0,0,-1,-1,-1,-1,-2,-2,-3,-2],[-1,1,-2,2,-1,1,-1,1,0,0],[0,0,1,1,1,1,2,2,3,2],[1,-1,2,-2,1,-1,1,-1,0,0]]
result=0 
def spread(t_x,t_y,dirr,cost):
    global result
    n_x,n_y=0,0;copy_cost=cost
    for i in range(9):
        n_x=t_x+dx[dirr][i];n_y=t_y+dy[dirr][i];value=int(cost*((0.01)*per[i]))
        if 0<=n_x<n and 0<=n_y<n:board[n_x][n_y]+=value
        else:result+=value
        copy_cost-=value
    n_x=t_x+dx[dirr][9];n_y=t_y+dy[dirr][9]
    if 0<=n_x<n and 0<=n_y<n:board[n_x][n_y]+=copy_cost
    else:result+=copy_cost
t_x,t_y=n//2,n//2;cnt=1;cost=0;x,y=t_x,t_y;alpha=1;d=-1;dirr=0;nx,ny=0,0
while alpha<n:
    for i in range(alpha):
        nx,ny=x,y;y+=d;cost=board[x][y];board[x][y]=0;spread(nx,ny,dirr,cost)
    d*=-1;dirr=(dirr+1)%4
    for i in range(alpha):
        nx,ny=x,y;x+=d;cost=board[x][y];board[x][y]=0;spread(nx,ny,dirr,cost)
    alpha+=1;dirr=(dirr+1)%4
for i in range(alpha-1):
    nx,ny=x,y;y+=d;cost=board[x][y];board[x][y]=0;spread(nx,ny,0,cost)
print(result)