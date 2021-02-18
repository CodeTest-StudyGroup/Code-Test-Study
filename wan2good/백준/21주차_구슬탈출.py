
from collections import deque
import sys
input=sys.stdin.readline
n,m=map(int,input().rstrip().split())
dx=[-1,0,1,0]
dy=[0,-1,0,1]

board=[]
def move(i,j,dx,dy):
    cnt=0
    curx,cury=i,j
    while board[curx+dx][cury+dy]!="#":
        if board[curx][cury]=='O':
            break
        curx,cury=curx+dx,cury+dy
        cnt+=1
    return curx,cury,cnt

def bfs(redx,redy,bluex,bluey):
    q=deque()
    q.append((redx,redy,bluex,bluey,1))
    visited=[[[[False for _ in range(m)] for _ in range(n)] for _ in range(m)] for _ in range(n)]
    visited[redx][redy][bluex][bluey]=True
    while q:
        redx,redy,bluex,bluey,d=q.popleft()
        if d>10:
            break
        for i in range(4):
            rednx,redny,rmove=move(redx,redy,dx[i],dy[i])
            bluenx,blueny,bmove=move(bluex,bluey,dx[i],dy[i])
            if board[bluenx][blueny]!="O":
                if board[rednx][redny]=="O":
                    return d
                if rednx==bluenx and redny==blueny:
                    if rmove>bmove:
                        rednx-=dx[i]
                        redny-=dy[i]
                    else:
                        bluenx-=dx[i]
                        blueny-=dy[i]
                if not visited[rednx][redny][bluenx][blueny]:
                    visited[rednx][redny][bluenx][blueny]=True
                    q.append((rednx,redny,bluenx,blueny,d+1))
    return -1

for _ in range(n):
    board.append(list(input().rstrip()))
for i in range(n):
    for j in range(m):
        if board[i][j]=='R':
            redx,redy=i,j
        if board[i][j]=='B':
            bluex,bluey=i,j

print(bfs(redx,redy,bluex,bluey))