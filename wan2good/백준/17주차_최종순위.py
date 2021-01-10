from collections import deque

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
t=int(input().rstrip())
for _ in range(t):
    n=int(input().rstrip())
    rank=list(MIS())
    
    indegree=[0]*(n+1)
    graph=[[0 for _ in range(n+1)] for _ in range(n+1)]
    for i in range(n):
        for j in  range(i+1,n):
            graph[rank[i]][rank[j]]=1
            indegree[rank[j]]+=1
    m=int(input().rstrip())
    for _ in range(m):
        a,b=MIS()
        if graph[a][b]:
            graph[a][b]=0
            graph[b][a]=1
            indegree[b]-=1
            indegree[a]+=1
        else:
            graph[b][a]=0
            graph[a][b]=1
            indegree[a]-=1
            indegree[b]+=1
    
    q=deque()
    for i in range(1,n+1):
        if indegree[i]==0: q.append(i)
    
    result=[]
    flag1=True;flag2=True
    for _ in range(n):
        if not q: flag1=False;break
        if len(q)>=2: flag2=False;break

        now=q.popleft()
        result.append(now)
        for i in range(1,len(graph[now])):
            indegree[i]-=1
            if indegree[i]==0: q.append(i)

    if not flag1: print('IMPOSSIBLE')
    elif not flag2: print('?')
    else:
        for i in result:
            print(i,end=' ')
        print()