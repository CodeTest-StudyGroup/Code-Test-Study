#2020 카카오 블록 이동하기

#https://medium.com/@dltkddud4403/2020-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EB%B8%94%EB%9D%BC%EC%9D%B8%EB%93%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%EB%B8%94%EB%A1%9D-%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0-57d668a744d0 참고함

dy = [-1,1,0,0]
dx = [0,0,-1,1]

MIN = 99999999999
def dfs(y1,x1,y2,x2,cnt,visited,board,N):
    global MIN
    if (y1 == N and x1 == N) or (y2 == N and x2 == N):
        MIN = min(MIN, cnt)
        return
        
    if cnt >= MIN:
        return

    for dir in range(0,8):
        if dir > 3:#rotation
            if y1 == y2: #가로 모양
                if dir == 4:
                    ny2 = y1+1
                    nx2 = x1
                    ny1,nx1 = y1,x1
                elif dir == 5:
                    ny2 = y1-1
                    nx2 = x1
                    ny1,nx1 = y1,x1
                elif dir == 6:
                    ny1 = y2+1
                    nx1 = x2
                    ny2,nx2 = y2,x2
                elif dir == 7:
                    ny1 = y2-1
                    nx1 = x2
                    ny2,nx2 = y2,x2
            else:#세로모양
                if dir == 4:
                    ny2 = y1
                    nx2 = x1+1
                    ny1,nx1 = y1,x1
                elif dir == 5:
                    ny2 = y1
                    nx2 = x1-1
                    ny1,nx1 = y1,x1
                elif dir == 6:
                    ny1 = y2
                    nx1 = x2+1
                    ny2,nx2 = y2,x2
                elif dir == 7:
                    ny1 = y2
                    nx1 = x2-1
                    ny2,nx2 = y2,x2

        else: #move
            ny1 = y1 + dy[dir]
            nx1 = x1 + dx[dir]
            ny2 = y2 + dy[dir]
            nx2 = x2 + dx[dir]

        if 0<=ny1<=N and 0<=ny2<=N and 0<=nx1<=N and 0<=nx2<=N:
            if board[ny1][nx1] == 0 and board[ny2][nx2] == 0 and [ny1,nx1,ny2,nx2] not in visited:
                visited.append([ny1,nx1,ny2,nx2])
                dfs(ny1,nx1,ny2,nx2,cnt+1,visited,board,N) 
                visited.pop() 

def next(y1,x1,y2,x2,board,N):
    ret = []
    for dir in range(0,4):
        ny1 = y1 + dy[dir]
        nx1 = x1 + dx[dir]
        ny2 = y2 + dy[dir]
        nx2 = x2 + dx[dir]
        if 0<=ny1<=N and 0<=ny2<=N and 0<=nx1<=N and 0<=nx2<=N and board[ny1][nx1] == 0 and board[ny2][nx2] == 0:
            ret.append({(ny1,nx1),(ny2,nx2)})

    rotate = [1,-1]
    for rot in rotate:
        #rotation #축의 대각선에 벽이없어야함 -> (무조건 board 값이 0이어야한다. index도 안에있어야함)
        if y1 == y2: #가로 모양
            if 0<=(y1+rot)<=N and 0<=(y2+rot)<=N and board[y1+rot][x1] == 0 and board[y2+rot][x2] == 0:
                ret.append({(y1,x1),(y1+rot,x1)})
                ret.append({(y2,x2),(y2+rot,x2)})

        else:#세로모양
            if 0<=(x1+rot)<=N and 0<=(x2+rot)<=N and board[y1][x1+rot] == 0 and board[y2][x2+rot] == 0:
                ret.append({(y1,x1),(y1,x1+rot)})
                ret.append({(y2,x2),(y2,x2+rot)})

    return ret

def bfs(y1,x1,y2,x2,board):
    queue = []
    queue.append([{(y1,x1),(y2,x2)},0])
    N = len(board) - 1
    cnt = 0
    visited = [{(0,0),(0,1)}]

    while queue:
        cur,dist = queue.pop(0)
        cur = list(cur)
        y1,x1,y2,x2 = cur[0][0],cur[0][1],cur[1][0],cur[1][1]
        #y1,x1,y2,x2,dist = queue.pop(0)

        if (y1 == N and x1 == N) or (y2 == N and x2 == N):
            cnt = dist
            break
        
        for n in next(y1,x1,y2,x2,board,N):
            if n not in visited:
                visited.append(n)
                queue.append([n,dist+1])

    return cnt



def solution(board):
    #dfs(0,0,0,1,0,visited,board,len(board)-1)
    #y1,x1,y2,x2,cnt,visited,board,N
    #answer = MIN
    answer = bfs(0,0,0,1,board)
    return answer


if __name__ == "__main__":
    print(solution([[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]))