from collections import deque
import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n,m,k=MIS();cost=[0]+list(MIS())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=MIS()
    graph[a].append(b)
    graph[b].append(a)

visited=[False for _ in range(n+1)]
def bfs(i):
    q=deque();q.append(i)
    minV=2e10
    while q:
        now=q.popleft()
        minV=min(minV,cost[now])
        for nextNode in graph[now]:
            if not visited[nextNode]:
                visited[nextNode]=True
                q.append(nextNode)
    return minV        

ans=0
for i in range(1,n+1):
    if not visited[i]:
        ans+=bfs(i)
print(ans) if ans<=k else print('Oh no')