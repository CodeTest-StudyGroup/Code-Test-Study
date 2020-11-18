from collections import deque
t=int(input())
def bfs(a,b):
    visited=[False]*10001
    q=deque();visited[a]=True;q.append((a,""))
    while q:
        now,o=q.popleft()
        if now==b:return o
        tmp=now*2%10000
        if not visited[tmp]:
            visited[tmp]=True;q.append((tmp,o+"D"))
        if now==0:tmp=9999
        else:tmp=now-1
        if not visited[tmp]:
            visited[tmp]=True;q.append((tmp,o+"S"))
        l=now//1000;tmp=(now-(1000*l))*10+l
        if not visited[tmp]:
            visited[tmp]=True;q.append((tmp,o+"L"))
        r=now%10;tmp=(r*1000)+(now//10)
        if not visited[tmp]:
            visited[tmp]=True;q.append((tmp,o+"R"))
for _ in range(t):
    a,b=map(int,input().split())
    print(bfs(a,b))