import sys,heapq
input = sys.stdin.readline

INF = 987654321
n,m,x = map(int,input().rstrip().split())
graph = [[] for _ in range(n+1)]

def dijkstra(start,end):
    distance = [INF]*(n+1)
    q = []
    distance[start] = 0
    heapq.heappush(q,(0,start))

    while q :
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))

    return distance[end]

for _ in range(m):
    a,b,c = map(int,input().rstrip().split())
    graph[a].append((b,c))

tmp=0; tmp2=0
result = -INF
for i in range(1,n+1):
    tmp = dijkstra(i,x)
    tmp2 = dijkstra(x,i)
    result = max(result,tmp+tmp2)

print(result)

