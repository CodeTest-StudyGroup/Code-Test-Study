from collections import deque
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
k=int(input().rstrip())

def bfs(q,color,x):
    q.append(x)
    color[x]=1
    while q:
        now=q.popleft()
        for i in graph[now]:
            if color[i]==0: color[i]=-1*color[now];q.append(i)
            elif color[i]==color[now]: return 1
    return 0

for _ in range(k):
    v,e=MIS()
    graph=[[] for _ in range(v+1)];color=[0]*(v+1)
    q=deque()
    for _ in range(e):
        x,y=MIS()
        graph[x].append(y);graph[y].append(x)
    ans=0
    for i in range(1,v+1):
        if color[i]==0:
            ans=bfs(q,color,i)
            if ans==1: break
    if ans==0: print('YES')
    else: print("NO")