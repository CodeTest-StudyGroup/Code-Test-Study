import sys
import collections
import heapq
dx = [-1,0,1,0]
dy = [0,1,0,-1]

INF = int(1e9)
n,m = map(int,input().split())
answer = int(1e9)
graph=[]
for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().rstrip().split())))


bridge=[] #오작교를 설치해야하는곳

time = 0 #현재 시간
can = True #오작교를 건널수 있을지 없을지


for x in range(n):
    for y in range(n):
        if graph[x][y]==0: #0일경우 체크
            cnt=0
            for i in range(len(dx)):
                dir_x = x+dx[i]
                dir_y = y+dy[i]
                if 0<=dir_x<n and 0<=dir_y<n:
                    if graph[dir_x][dir_y]==0: #한면이 0이면 수직하는지 체크해야하므로
                        if i==0:
                            check1_x= x+dx[3]
                            check1_y = y+dy[3]
                            check2_x = x+dx[1]
                            check2_y = y+dy[1]
                        else:
                            check1_x = x+dx[(i+1)%4]
                            check1_y = y+dy[(i+1)%4]
                            check2_x = x+dx[(i-1)%4]
                            check2_y = y+dy[(i-1)%4]
                        if 0<=check1_x<n and 0<=check1_y<n and 0<=check2_x<n and 0<=check2_y<n:
                            if graph[check1_x][check1_y]==0 or graph[check2_x][check2_y]==0:
                                graph[x][y]=-1 #건널수 없는곳
            if graph[x][y]!=-1:
                bridge.append((x,y))

def bfs(tup):
    heap = []
    arr = [[INF]*n for _ in range(n)] #최소시간 저장 배열
    if tup[0]==0 and tup[1]==0:
        pass
    else:
        graph[tup[0]][tup[1]]=m
    heapq.heappush(heap,(0,0,0,False)) #현재 시간, x y 오작교를 건너고왔는지 (0일경우 안건너왔다는뜻.)
    arr[0][0] = 0
    while heap:
        cur,x,y,flag =heapq.heappop(heap)
        for i in range(len(dx)):
            dir_x =x+dx[i]
            dir_y = y+dy[i]
            if 0<=dir_x<n and 0<=dir_y<n:
                if graph[dir_x][dir_y] ==1: #1로 건너갈경우
                    if arr[dir_x][dir_y]>cur+1:
                        arr[dir_x][dir_y] = cur+1
                        heapq.heappush(heap,(arr[dir_x][dir_y],dir_x,dir_y,False))
                elif 1<graph[dir_x][dir_y]:
                    if flag==True:
                        continue
                    # temp=cur
                    # if temp==0:
                    #     temp+=1
                    # if temp%graph[dir_x][dir_y]==0:
                    #     temp+=1
                    # else:
                    #     while temp%graph[dir_x][dir_y]!=0:
                    #         temp+=1
                    temp = cur+1
                    if temp%graph[dir_x][dir_y]!=0:
                        while temp%graph[dir_x][dir_y]!=0:
                            temp+=1

                    if arr[dir_x][dir_y]>temp:
                        arr[dir_x][dir_y]=temp
                        heapq.heappush(heap,(arr[dir_x][dir_y],dir_x,dir_y,True))
    if tup[0]==0 and tup[1]==0:
        pass
    else:
        graph[tup[0]][tup[1]]=0
    global answer
    if arr[n-1][n-1]<answer:
        answer=arr[n-1][n-1]



if len(bridge)==0:
    bfs((0,0))

else:
    for i in range(len(bridge)): #
        bfs(bridge[i])


print(answer)