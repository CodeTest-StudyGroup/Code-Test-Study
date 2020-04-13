#탈주범 검거


'''
BFS
DFS보단 뭔가 좀 더 간단한 느낌이다. 재귀를 안쓰고 움직인 부분을 큐에 넣고 큐를 빼면서 다시 움직일 수 있는 공간을 큐에넣고,,
집중 빡해서 신경써서 하면 괜찮을 것 같은느낌?

MAP[pos[0]][pos[1]] in [1,2,4,7] 이런식으로 and, and 안하고 바로 조건식 만들 수 있다.
'''

def bfs(cnt, y,x, visited):
    queue = list()
    queue.append((y,x))
    
    while cnt <= L:
        for _ in range(len(queue)):
            pos = queue.pop(0)
            visited[pos[0]][pos[1]] = 1

            for dir in range(0,4):
                newy = pos[0] + dy[dir]
                newx = pos[1] + dx[dir]
                if 0<= newx < M and 0<= newy < N:
                    if dir == 0 and MAP[pos[0]][pos[1]] in [1,2,4,7] and MAP[newy][newx] in [1,2,5,6]:
                        queue.append((newy, newx))
                    elif dir == 1 and MAP[pos[0]][pos[1]] in [1,2,5,6] and MAP[newy][newx] in [1,2,4,7]:
                        queue.append((newy, newx))
                    elif dir == 2 and MAP[pos[0]][pos[1]] in [1,3,6,7] and MAP[newy][newx] in [1,3,4,5]:
                        queue.append((newy, newx))
                    elif dir == 3 and MAP[pos[0]][pos[1]] in [1,3,4,5] and MAP[newy][newx] in [1,3,6,7]:
                        queue.append((newy, newx))
            MAP[pos[0]][pos[1]] = 0
        cnt += 1


if __name__ == "__main__":
    T = int(input())
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    
    for TC in range(1,T+1):
        N,M,R,C,L = map(int,input().split())

        MAP = [list(map(int, input().split())) for _ in range(N)]
        
        cnt = 0
        visited = [[0 for _ in range(M)]for _ in range(N)]
        bfs(1, R,C, visited)

        for i in range(0,N):
            for j in range(0,M):
                if visited[i][j] == 1:
                    cnt += 1

        print("#%d %d" %(TC,cnt))