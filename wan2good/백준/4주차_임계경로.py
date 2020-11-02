import sys
from collections import deque
input = sys.stdin.readline

n = int(input().rstrip())
m = int(input().rstrip())

graph1 = [[] for _ in range(n+1)]
graph2 = [[] for _ in range(n+1)]
indegree = [0]*(n+1)
for _ in range(m):
    a,b,c = map(int,input().rstrip().split())
    graph1[a].append((b,c))
    graph2[b].append((a,c))
    indegree[b] +=1

start, end = map(int,input().rstrip().split())
distance = [0] * (n+1)
check = [0] * (n+1)

def topology_sort():
    q = deque()
    q.append(start)

    while q:
        i = q.popleft()
        for item in graph1[i]:
            if distance[item[0]] <= item[1] + distance[i]:
                distance[item[0]] = item[1] + distance[i]
            
            indegree[item[0]] -= 1
            if indegree[item[0]] == 0:
                q.append(item[0])

    cnt = 0
    q.append(end)
    while q:
        j = q.popleft()
        for item in graph2[j]:
            if distance[j]-distance[item[0]] == item[1]:
                cnt+=1
                if check[item[0]] == 0:
                    q.append(item[0])
                    check[item[0]]=1


    print(distance[end])
    print(cnt)

topology_sort()