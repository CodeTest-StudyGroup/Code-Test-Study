from heapq import heappop,heappush
import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n,p,k=MIS()
graph=[[] for _ in range(n+1)]
for _ in range(p):
    a,b,c=MIS()
    graph[a].append((b,c))
    graph[b].append((a,c))

def dijkstra(start,mid):
    pq=[]
    heappush(pq,(0,start))
    distance=[2e10 for _ in range(n+1)]
    distance[start]=0
    while pq:
        dist,now=heappop(pq)
        if dist>distance[now]:
            continue

        for nextNode,nextCost in graph[now]:
            if mid<=nextCost:
                cost=dist+1
            else:
                cost=dist
            if cost<distance[nextNode]:
                distance[nextNode]=cost
                heappush(pq,(cost,nextNode))
    
    return True if distance[n]<=k else False

l,r=1,987654321
ans=0
while l<=r:
    mid=(l+r)//2
    if dijkstra(1,mid):
        r=mid-1
    else:
        l=mid+1
        ans=mid
print(ans) if ans!=987654321 else print(-1)