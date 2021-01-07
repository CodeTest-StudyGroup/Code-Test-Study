input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip());m=int(input().rstrip())
INF=2e10
graph=[[INF for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m):
    a,b=MIS()
    graph[a][b]=1

for i in range(1,n+1):
    graph[i][i]=0

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b])

for node in range(1,n+1):
    cnt=n
    for node2 in range(1,n+1):
        if graph[node][node2]!=INF or graph[node2][node]!=INF: cnt-=1
    print(cnt)