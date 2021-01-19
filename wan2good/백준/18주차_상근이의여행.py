from collections import deque

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
t=int(input().rstrip())

def bfs(x,graph):
    q=deque()
    q.append(x)
    visited[x]=True
    cnt=0
    while q:
        now=q.popleft()
        for nextNode in graph[now]:
            if not visited[nextNode]:
                visited[nextNode]=True
                q.append(nextNode)
                cnt+=1
    return cnt

for _ in range(t):
    n,m=MIS()
    graph=[[] for _ in range(n+1)]
    visited=[False for _ in range(n+1)]
    for _ in range(m):
        a,b=MIS()
        graph[a].append(b);graph[b].append(a)
    result=0
    for i in range(1,n+1):
        result+=bfs(i,graph)
    print(result)