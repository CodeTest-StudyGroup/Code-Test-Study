#1949 "등산로 조성"
#문자열에서는 find 되는데 정수 리스트에서는 find 안됨...그래서 인덱스 찾으려면 index를 써야한다.

def Insafe(old_y,old_x,y,x):
    global flag
    if 0<=y<N and 0<=x<N:#먼저 좌표안에 있어야한다.
        if MAP[old_x][old_y] > MAP[x][y]: #이전의 봉우리보다 낮아야한다.
            return 1 #y,x 로 움직일 수 있다.
        else:#만약 낮지않다면
            #MAP[x][y]를 MAP[old_x][old_y]보다 딱 한 칸 낮게 만들면 된다.
            
            depth = MAP[x][y] - MAP[old_x][old_y] + 1
            if MAP[x][y] == 0: #더 이상 못깎을 때
                return 0
            if flag == 1 and K >= depth:
                #봉우리를 낮출 수 있다면
                #낮출 수도 있고 k의 값이 충분하다.
                flag == 1 
                MAP[x][y] -=depth
                return 1

            else:#k의 값이 충분하지 못하거나 이미 깎았다면.
                return 0 #못간다.


def dfs(y,x):
    global Distance
    global MaxDistance
    visited.append((y,x))
    for dir in range(0,4):
        new_y = y + dx[dir]
        new_x = x + dy[dir]

        if new_y  == start_y and new_x == start_x:#원점으로 돌아오면 distance 길이 비교해서 초기화
            if Distance > MaxDistance:
                MaxDistance = Distance
            Distance = 0

        if Insafe(y,x,new_y, new_x) and (new_y, new_x) not in visited:
            Distance += 1 #y,x로 가면 distance 가 늘어난다.
            dfs(new_y,new_x)

    
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
                topList.append((x,y))

    dy = [-1,1,-0,0]
    dx = [0,0,-1,1]
    MaxDistance = -999
    
    if topList: #봉우리 개수만큼 출발점
        visited = list()
        Distance = 0
        start = topList.pop()
        start_y, start_x = start[0],start[1]
        dfs(start_y,start_x)

    print(MaxDistance)

    '''
10
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
    
    '''