import sys
from math import sqrt
from itertools import combinations
def find_parent(parent,x):
    if parent[x]!=x:parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b: parent[b]=a
    else: parent[a]=b

input=__import__('sys').stdin.readline
MIS=lambda: map(int,input().split())
n,m=MIS();data=[[0,0]];parent=[0]*(n+1);edges=[]
for _ in range(n):
    data.append(list(MIS()))
for i in range(1,n+1):
    parent[i]=i

combis = list(combinations(range(1,n+1),2))
for _ in range(m):
    a,b=MIS()
    if find_parent(parent,a)!=find_parent(parent,b):
        union_parent(parent,a,b)
    if (a,b) in combis:
        combis.remove((a,b))
for combi in combis:
    a,b=combi
    x1,y1=data[a]
    x2,y2=data[b]
    cost=sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2))
    edges.append((cost,a,b))

result=0;edges.sort()
for edge in edges:
    cost,a,b=edge
    if find_parent(parent,a)!=find_parent(parent,b):
        union_parent(parent,a,b);result+=cost
print('%.2f' % result)