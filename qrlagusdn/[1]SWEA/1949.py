#1949 "등산로 조성"
#문자열에서는 find 되는데 정수 리스트에서는 find 안됨...그래서 인덱스 찾으려면 index를 써야한다.
 
 
def dfs(Distance, y,x,visited):
    global MaxDistance
    global K
    global flag
     
    for dir in range(0,4):
        new_y = y + dy[dir]
        new_x = x + dx[dir]
            #Insafe(y,x,, new_x) 
        if 0<=new_y MAP[new_y][new_x]: #이전의 봉우리보다 낮아야한다.
            #y,x 로 움직일 수 있다.
                visited.append((new_y,new_x))
                Distance += 1
                dfs(Distance, new_y,new_x,visited)
 
                if Distance >= MaxDistance:
                    MaxDistance = Distance
 
                ############되돌리는 부분
                Distance -= 1
                visited.pop()
         
            else :#만약 낮지않다면
                #MAP[x][y]를 MAP[old_x][old_y]보다 딱 한 칸 낮게 만들면 된다.
                 
                depth = MAP[new_y][new_x] - MAP[y][x] + 1
 
                if flag == 1 and K >= depth and MAP[new_y][new_x] != 0:
                    #봉우리를 낮출 수 있다면
                    #낮출 수도 있고 k의 값이 충분하다.
                    flag = 0
                    MAP[new_y][new_x] -= depth
 
                    visited.append((new_y,new_x))
 
                    Distance += 1
                    dfs(Distance, new_y,new_x,visited)
 
                    if Distance >= MaxDistance:
                        MaxDistance = Distance
 
                    ############되돌리는 부분
                    visited.pop()
                    Distance -=1
                    MAP[new_y][new_x] += depth #map 부분 다시 되돌리기
                    flag = 1
 
     
T = int(input())
for TC in range(1, T + 1):
    flag = 1 #지형 깎는 공사 진행했는지 안했는지
    N, K = map(int, input().split())
    MAP = list()
    top = 0 #최고 높이 봉우리 찾기
    topList = list()
    for i in range(N):#지도 입력
        arr = list(map(int,input().split()))
        MAP.append(arr)
        if top <= max(arr):
            top = max(arr)
 
    for y in range(0,N):
        for x in range(0,N):
            if MAP[y][x] == top:
                topList.append((y,x))
 
    dy = [-1,1,-0,0]
    dx = [0,0,-1,1]
    MaxDistance = -999
     
    j = len(topList)
    for i in range(j): #봉우리 개수만큼 출발점
        visited = list()
        Distance = 1
        start = topList.pop()
        start_y, start_x = start[0],start[1]
        visited.append((start_y, start_x))#시작점 추가
 
        dfs(Distance, start_y,start_x,visited)  
    print("#%d %d" %(TC,MaxDistance))
