import sys
from bisect import bisect_left,bisect_right
sys.setrecursionlimit(10**6)
input=sys.stdin.readline

n=int(input().rstrip())
parent=[i for i in range(1000001)]
cnt=[1 for i in range(1000001)]
def find_parent(parent,x):
    if parent[x]!=x: parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a!=b:
        if a<b:
            parent[b]=a
            cnt[a]+=cnt[b]
            cnt[b]=0
        else:
            parent[a]=b
            cnt[b]+=cnt[a]
            cnt[a]=0

for _ in range(n):
    data=list(input().rstrip().split())
    if data[0]=='I':
        union(parent,int(data[1]),int(data[2]))
    elif data[0]=='Q':
        print(cnt[find_parent(parent,int(data[1]))])