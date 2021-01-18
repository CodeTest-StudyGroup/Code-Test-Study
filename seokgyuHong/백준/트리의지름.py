import sys
import collections
v = int(input())
INF = int(1e9)

graph = [[] for _ in range(v+1)]
visited = [False]*(v+1)
distance = [0]*(v+1)
deq = collections.deque()
#visited[1] = True
deq.append((1,0))


for _ in range(v):
    temp = list(map(int,sys.stdin.readline().rstrip().split()))
    start = temp[0]
    end = 0
    dist = 0
    for i in range(1,len(temp)):
        if temp[i]==-1:
            break
        if i%2!=0:
            end=temp[i]
        if i%2==0:
            dist=temp[i]
            graph[start].append((end,dist))




max = 0
idx =0
visited[1]=True
while deq:
    start,cost = deq.popleft() #시작
    for i in graph[start]:
        if visited[i[0]]==False:
            visited[i[0]]=True
            deq.append((i[0],cost+i[1]))
            if max <cost+i[1]:
                max = cost+i[1]
                idx = i[0]

#print(idx)
visited = [False]*(v+1)

visited[idx]=True
deq.append((idx,0))
max2 =0
while deq:
    start,cost = deq.popleft() #시작
    for i in graph[start]:
        if visited[i[0]]==False:
            visited[i[0]]=True
            deq.append((i[0],cost+i[1]))
            if max2 <cost+i[1]:
                max2 = cost+i[1]
                idx = i[0]


print(max2)