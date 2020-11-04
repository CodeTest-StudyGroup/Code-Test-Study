import sys,heapq
input = sys.stdin.readline

n,m = map(int,input().rstrip().split())
fox = [[] for _ in range(n+1)]
wolf = [[] for _ in range(2*n+1)]

INF = 2e10
# distance2 = [[INF,INF] for _ in range(n+1)]



def dijkstra1(start,n):
    distance1 = [INF]*(n+1)
    distance1[start] = 0
    q = []
    heapq.heappush(q,(0,start))
    while q:
        dist, now = heapq.heappop(q)
        if distance1[now] < dist:
            continue
        for i in fox[now]:
            cost = dist + i[1]
            if cost < distance1[i[0]]:
                distance1[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))
    return distance1
def dijkstra2(start,n):
    distance2 = [INF]*(n+1)
    distance2[start] = 0
    q = []
    heapq.heappush(q,(0,start))
    while q:
        dist, now = heapq.heappop(q)
        if distance2[now] < dist:
            continue
        for i in wolf[now]:
            cost = dist + i[1]
            if cost < distance2[i[0]]:
                distance2[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))                
    return distance2

for _ in range(m):
    a,b,c = map(int,input().rstrip().split())
    fox[a].append((b,2*c))
    fox[b].append((a,2*c))
    wolf[a].append((n+b,c))
    wolf[n+a].append((b,4*c))
    wolf[b].append((n+a,c))
    wolf[n+b].append((a,4*c))

size1 = len(fox)-1
size2 = len(wolf)-1
result1= dijkstra1(1,size1) # 여우
result2 = dijkstra2(1,size2) # 늑대

cnt = 0
for i in range(1,n+1):
    if result1[i] < min(result2[i], result2[i+n]):
        cnt+=1

print(cnt)
    