from collections import deque
import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n=int(input().rstrip())
time=[0]*(n+1)
indegree=[0]*(n+1)
graph=[[] for _ in range(n+1)]
for i in range(1,n+1):
    data=list(MIS())
    time[i]=data[0]
    indegree[i]+=data[1]
    for j in range(2,2+data[1]):
        graph[data[j]].append(i)

q=deque()
result=[0]*(n+1)
for i in range(1,n+1):
    result[i]=time[i]
    if indegree[i]==0:
        q.append(i)

while q:
    now=q.popleft()

    for i in graph[now]:
        result[i]=max(result[i],result[now]+time[i])

        indegree[i]-=1
        if indegree[i]==0:
            q.append(i)

print(max(result[1:]))