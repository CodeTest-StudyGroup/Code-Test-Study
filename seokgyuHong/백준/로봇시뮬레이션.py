import sys
a,b = map(int,input().split())
n,m = map(int,input().split())

arr =[]
for i in range(101):
    temp = [-1 for j in range(101)]
    arr.append(temp)

for i in range(b+1):
    temp = [0 for j in range(a+1)]
    arr.append(temp)
start_x =100
start_y=1
cnt=0
while(cnt<b):
    cnt2=0
    start_y=1
    while(cnt2<a):
        arr[start_x][start_y]=0
        cnt2+=1
        start_y+=1
    start_x-=1
    cnt+=1
cnt=1
robot=[]
robot.append(0) #방향만 저장
for i in range(n):
    x,y,h = map(str,sys.stdin.readline().rstrip().split())
    x = int(x)
    y = int(y)
    arr[100-y+1][x] = cnt #로봇번호저장
    robot.append([y,x,h])
    cnt+=1
flag = True
for i in range(m):
    num,turn,count = map(str,sys.stdin.readline().rstrip().split())
    num = int(num)
    count = int(count)
    for j in range(count):
        x,y = robot[num][1],robot[num][0]
        cur = robot[num][2]
        if turn =='L':
            if cur=='N':
                cur='W'
            elif cur=='W':
                cur='S'
            elif cur=='S':
                cur='E'
            else:
                cur='N'
        elif turn=='R':
            if cur=='N':
                cur='E'
            elif cur=='E':
                cur='S'
            elif cur=='S':
                cur='W'
            else:
                cur='N'
        else: #turn ==F
            if cur=='N':
                y = y+1
                if 100-y+1 ==0 or arr[100-y+1][x]==-1: #벽에박을때
                    print('Robot {} crashes into the wall'.format(num))
                    flag=False
                    break
                elif arr[100-y+1][x]!=0:
                    print('Robot {} crashes into robot {}'.format(num,arr[100-y+1][x]))
                    flag=False
                    break
                else:
                    arr[100-y+1][x] = num
                    arr[100-y+2][x] = 0
            elif cur=='E':
                x = x+1
                if x>a or arr[100-y+1][x]==-1: #범위를 벗어났거나 벽일경우
                    print('Robot {} crashes into the wall'.format(num))
                    flag=False
                    break
                elif arr[100-y+1][x] != 0:
                    print('Robot {} crashes into robot {}'.format(num, arr[100-y+1][x]))
                    flag = False
                    break
                else:
                    arr[100-y+1][x] = num
                    arr[100-y+1][x-1] = 0
            elif cur=='S':
                y = y-1
                if 100-y+1==101 or arr[100-y+1][x]==-1:
                    print('Robot {} crashes into the wall'.format(num))
                    flag=False
                    break
                elif arr[100-y+1][x]!=0:
                    print('Robot {} crashes into robot {}'.format(num,arr[100-y+1][x]))
                    flag=False
                    break
                else:
                    arr[100-y+1][x]=num
                    arr[100-y][x]=0
            else:
                x =x-1
                if x==0 or arr[100-y+1][x]==-1:
                    print('Robot {} crashes into the wall'.format(num))
                    flag=False
                    break
                elif arr[100-y+1][x] != 0:
                    print('Robot {} crashes into robot {}'.format(num, arr[100-y+1][x]))
                    flag = False
                    break
                else:
                    arr[100-y+1][x] = num
                    arr[100-y+1][x+1] = 0

        robot[num][1],robot[num][0] = x,y
        robot[num][2] = cur
    if flag==False:
        break

if flag==True:
    print('OK')


