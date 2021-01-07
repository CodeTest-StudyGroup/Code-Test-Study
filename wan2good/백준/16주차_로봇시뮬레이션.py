import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

a,b=MIS();n,m=MIS();robot=[[]];order=[]
dx=[-1,0,1,0];dy=[0,-1,0,1]
direction=0
for _ in range(n):
    y,x,op=input().rstrip().split()
    if op=='N': op=2
    elif op=='W': op=1
    elif op=='S': op=0
    elif op=='E': op=3
    y=int(y);x=int(x)
    robot.append([x,y,op])

for _ in range(m):
    num,op,cnt=input().rstrip().split()
    num=int(num);cnt=int(cnt)
    order.append([num,op,cnt])

board=[[[0,0,0] for _ in range(a+1)] for _ in range(b+1)]
cnt=1
for i in range(1,len(robot)):
    x,y,dir_=robot[i]
    board[x][y][0],board[x][y][1],board[x][y][2]=1,dir_,cnt
    cnt+=1

for num,op,cnt in order:
    num=int(num);cnt=int(cnt)
    type_=3
    if op=='F':
        for _ in range(cnt):
            nx,ny=robot[num][0]+dx[robot[num][2]],robot[num][1]+dy[robot[num][2]]
            if nx<1 or ny<1 or nx>b or ny>a: 
                print("Robot {} crashes into the wall".format(num))
                sys.exit()
            elif board[nx][ny][0]==1 :
                print("Robot {} crashes into robot {}".format(num,board[nx][ny][2]))
                sys.exit()
            else:
                board[robot[num][0]][robot[num][1]][0],board[robot[num][0]][robot[num][1]][1],board[robot[num][0]][robot[num][1]][2]=0,0,0
                robot[num][0],robot[num][1]=nx,ny
                board[robot[num][0]][robot[num][1]][0],board[robot[num][0]][robot[num][1]][1],board[robot[num][0]][robot[num][1]][2]=1,robot[num][2],num
    elif op=='L':
        for _ in range(cnt):
            robot[num][2]-=1
            if robot[num][2]==-1: robot[num][2]=3
        board[robot[num][0]][robot[num][1]][1]=robot[num][2]
    elif op=='R':
        for _ in range(cnt):
            robot[num][2]+=1
            if robot[num][2]==4: robot[num][2]=0
        board[robot[num][0]][robot[num][1]][1]=robot[num][2]

print('OK')
