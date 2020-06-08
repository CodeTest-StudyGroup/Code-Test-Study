#3190 삼성기출 뱀

dy = [-1,0,1,0] # 상 우 하 좌
dx = [0,1,0,-1]

if __name__ =="__main__":
    N = int(input())
    K = int(input())
    MAP = [[0 for _ in range(N)]for _ in range(N)]
    for i in range(K):
        y,x = map(int,input().split())
        MAP[y-1][x-1] = 1
    L = int(input())
    arr = [list(map(str,input().split())) for _ in range(L)]
    
    visited = list()
    
    y,x,dir = 0,0,1
    time = 0
    tail = (y,x)
    head = (y,x)
    
    i = 0
    while 1:
        visited.append(head)
        
        if i < len(arr) and time == int(arr[i][0]):
            if arr[i][1] == 'D':
                dir = (dir+1)%4
            elif arr[i][1] == 'L':
                dir = (dir+3)%4
            i += 1

        y = y+dy[dir]
        x = x+dx[dir]
        
        if y<0 or y>=N or x<0 or x>=N or (y,x) in visited: #맵 밖이거나, 자기 몸에 부딪히면
            break

        head = (y,x)
        if MAP[y][x] == 1: #사과가 있으면
            MAP[y][x] = 0 #사과 없애기
        else:
            tail = visited.pop(0)
        
        time += 1
    
    print(time+1)