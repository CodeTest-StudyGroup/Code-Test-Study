from collections import deque

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
v=int(input().rstrip());adj=[[] for _ in range(v+1)]
for _ in range(v):
    data=list(MIS())
    for i in range(1,len(data)-2,2):
        adj[data[0]].append((data[i],data[i+1]))

def bfs(start):
    maxNode,maxDist=0,0
    check=[False]*(v+1);check[start]=True
    q=deque();q.append((start,0))
    while q:
        now,dist=q.popleft()
        for nextNode,cost in adj[now]:
            if not check[nextNode]:
                check[nextNode]=True
                q.append((nextNode,cost+dist))
                if maxDist<cost+dist:
                    maxDist=cost+dist
                    maxNode=nextNode
    return maxNode,maxDist

node,dist=bfs(1)
print(bfs(node)[1])