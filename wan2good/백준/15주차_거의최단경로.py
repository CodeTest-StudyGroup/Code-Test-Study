import heapq
from collections import deque
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
INF=2e10

while True:
    n,m=MIS()
    if n==0 and m==0: break
    s,e=MIS()
    graph=[{} for _ in range(n)]
    re_graph=[[] for _ in range(n)]
    check=set()
    for _ in range(m):
        u,v,p=MIS()
        graph[u][v]=p
        re_graph[v].append(u)

    def dijkstra(start,end):   
        distance=[INF]*n
        distance[start]=0
        q=[]
        heapq.heappush(q,(0,start))
        while q:
            dist,now=heapq.heappop(q)
            if dist>distance[now]: continue

            for i in graph[now]:
                cost=graph[now][i]
                if distance[i]>distance[now]+cost:
                    distance[i]=distance[now]+cost
                    heapq.heappush(q,(distance[i],i))
        return distance
    
    distance=dijkstra(s,e)

    def bfs():
        q=deque();q.append(e)
        while q:
            now=q.popleft()
            if now==s: continue
            for prev_node in re_graph[now]:
                if distance[now]==distance[prev_node]+graph[prev_node][now]:
                    if (prev_node,now) not in check:
                        check.add((prev_node,now))
                        q.append((prev_node))
    bfs()
    for a,b in check:
        del graph[a][b]
    distance=dijkstra(s,e)

    print(distance[e] if distance[e]!=INF else -1)