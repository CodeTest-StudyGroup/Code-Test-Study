from collections import deque

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,m=MIS()

graph=[[] for _ in range((n**2))]
for _ in range(m):
    sx,sy,ex,ey=MIS()
    graph[((sx-1)*n)+sy-1].append(((ex-1)*n)+ey-1)
    
visited2=[False]*((n**2))
check=[[False for _ in range(n)] for _ in range(n)]
dx=[-1,0,1,0];dy=[0,-1,0,1]
while True:
    q=deque();q.append((0,0))
    visited=[[False for _ in range(n)] for _ in range(n)]
    visited[0][0]=True;check[0][0]=True
    flag=False
    while q:
        x,y=q.popleft()
        now=x*n+y
        for nextNode in graph[now]:
            if not visited2[nextNode]:
                flag=True
                visited2[nextNode]=True
                row=nextNode//n;col=nextNode%n
                check[row][col]=True
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<n and check[nx][ny] and not visited[nx][ny]:
                visited[nx][ny]=True
                q.append((nx,ny))
    if not flag: break

cnt=0    
for row in check:
    for col in row:
        if col: cnt+=1
print(cnt)