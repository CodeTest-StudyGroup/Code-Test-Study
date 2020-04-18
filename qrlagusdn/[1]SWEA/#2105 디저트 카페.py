#2105 swea 디저트 카페

dy = [1,1,-1,-1] #우하 좌하 상좌 우상
dx = [1,-1,-1,1] #우하 좌하 상좌 우상
answer = 0
def dfs(y,x, start_y,start_x, flag,visited,dessert,count):
    global answer

    ################
    #예외처리 극혐
    #일단 사각형 안그리고 돌아오는 경우 제외하기 위해서 flag라는 방향을 정하고 3일때만 max 체크함
    #그리고 사각형 그리기 전에 즉, 대각선으로만 움직이는 경우 체크하기위해서 count해서 4이상일때만 체크함

    ###############
    if count>=4 and flag == 3 and y == start_y and x == start_x:
        answer = max(answer,visited[y][x])
        return
    
    if flag == -1: 
        flag = 0 #맨첨에

    if flag == 4:
        return
    
    newy = y+dy[flag]
    newx = x+dx[flag]
    
    if 0<=newy<N and 0<=newx<N and visited[newy][newx] <= 1:
        if MAP[newy][newx] not in dessert:
            if flag == 2 and newy == start_y and newx == start_x: #역주행
                return
            
            visited[newy][newx] = visited[y][x] + 1
            dessert.append(MAP[newy][newx])
            dfs(newy,newx,start_y,start_x,flag,visited,dessert,count+1)
            visited[newy][newx] = 0
            dessert.pop()
    
    flag += 1 #방향 조절
    dfs(y,x,start_y,start_x,flag,visited,dessert,count)


def bfs(start_y,start_x):
    queue = list()
    queue.append((start_y,start_x))
    flag = -1 #0:우하, 1:좌하 2:상좌 3:우상 순서대로        처음 시작할때는 -1

    visited = [[0 for _ in range(N)]for _ in range(N)]
    visited[start_y][start_x] = 1
    dessert = list()

    while queue:
        pos = queue.pop(0)
        y = pos[0]
        x = pos[1]
        if flag != -1 and y == start_y and x == start_x:
            return visited[y][x]

        if flag == -1:
            flag = 0

        newy = y+dy[flag]
        newx = x+dx[flag]

        if 0<=newy<N and 0<=newx<N and visited[newy][newx] == 0:
            if MAP[newy][newx] not in dessert:
                dessert.append(MAP[newy][newx])
                queue.append((newy,newx))
                visited[newy][newx] = visited[y][x] + 1

        else:
            if flag == 3: #계속 가다가 막히면 방향전환
                flag = 0
            else: 
                flag += 1
#bfs로 했다가 감이 안와서 실패



if __name__ == "__main__":
    T = int(input())

    for TC in range(1,T+1):
        N = int(input())
        MAP = [list(map(int,input().split())) for _ in range(N)]
        answer = 0
        for y in range(0,N):
            for x in range(0,N):
                visited = [[0 for _ in range(N)]for _ in range(N)]
                visited[y][x] = 1
                #dessert = [MAP[y][x]]
                dessert = []
                dfs(y,x,y,x,-1,visited,dessert,0)
        if answer == 1:
            print("#%d %d" %(TC,-1))
        else:
            print("#%d %d" %(TC,answer-1))
'''10               
4                
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5

1
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
'''