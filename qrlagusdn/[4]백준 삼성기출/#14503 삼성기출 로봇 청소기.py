#14503 삼성기출 로봇 청소기

dy = [-1,0,1,0]#0 상, 1 우, 2하, 3 좌
dx = [0,1,0,-1]
answer = 0

def dfs(y,x,d,cnt,flag,visited):
    visited[y][x] = 1
    while 1:
        #청소도 안했고, 벽이 아니면 돌아
        #그게 아니면 후진 보고 할 수 있으면 후진, 못하면 return
        flag = 0
        for dir in range(0,4):
            if MAP[y+dy[dir]][x+dx[dir]] == 0 and visited[y+dy[dir]][x+dx[dir]] == 0: #청소도안했고, 벽이 아닌 곳이 있다면
                flag = 1
                
        if flag == 0: #못감
            if d in [0,1]: #후진 보기// 상, 우 이면
                newy = y+dy[d+2]
                newx = x+dx[d+2]
            else:
                newy = y+dy[d-2]
                newx = x+dx[d-2]

            if MAP[newy][newx] == 1: #후진이 벽이면
                return cnt
            else:
                y = newy
                x = newx
                flag = 0
                continue
        else:
            #방향 기준 왼쪽 : 0 -> 3, 1-> 0, 2-> 1, 3-> 2
            # (d+3) % 4
            d = (d+3)%4
            flag += 1 #회전 횟수
            newy = y+dy[d]
            newx = x+dx[d]
            if MAP[newy][newx] == 0 and visited[newy][newx] == 0: #청소할 공간 존재하면 방향바꾸고 전진
                y,x = newy,newx
                cnt += 1
                visited[y][x] = 1
            
            '''else:#청소할 공간 없으면 방향만 바꿈
                flag = 0'''


if __name__ == "__main__":
    N,M = map(int,input().split())
    r,c,d = map(int,input().split())

    MAP = [list(map(int,input().split())) for _ in range(N)]
    visited = [[0 for _ in range(M)]for _ in range(N)]
    answer = dfs(r,c,d,1,0,visited)
    print(answer)