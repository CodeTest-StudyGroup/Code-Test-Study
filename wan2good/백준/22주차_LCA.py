from collections import deque
import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n=int(input().rstrip())
tree=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=MIS()
    tree[a].append(b)
    tree[b].append(a)

q=deque(); q.append(1)
parent=[0]*(n+1); parent[1]=1
depth=[0]*(n+1); depth[1]=1
while q:
    now=q.popleft()
    for nextNode in tree[now]:
        if parent[nextNode]==0:
            parent[nextNode]=now
            depth[nextNode]=depth[now]+1
            q.append(nextNode)

m=int(input().rstrip())
for _ in range(m):
    a,b=MIS()
    depA,depB=depth[a],depth[b]

    if depA>depB:
        while depA!=depB:
            a=parent[a]
            depA=depth[a]
    else:
        while depB!=depA:
            b=parent[b]
            depB=depth[b]

    while parent[a]!=parent[b]:
        a=parent[a]
        b=parent[b]
    print(parent[a]) if a!=b else print(a)