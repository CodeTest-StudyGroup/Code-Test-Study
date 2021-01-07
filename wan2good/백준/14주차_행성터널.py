input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip());pos=[];edges=[]

def find_parent(parent,x):
    if parent[x]!=x: parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b: parent[b]=a
    else: parent[a]=b

for i in range(n):
    x,y,z=MIS()
    pos.append((x,y,z,i))

for i in range(3):
    pos.sort(key=lambda x:x[i])
    before=pos[0][3]
    for j in range(1,n):
        current=pos[j][3]
        edges.append([abs(pos[j][i]-pos[j-1][i]),before,current])
        before=current
edges.sort()
parent=[i for i in range(n)]
cnt=0;result=0
for edge in edges:
    if cnt==n: break
    cost,a,b=edge
    if find_parent(parent,a)!=find_parent(parent,b):
        union_parent(parent,a,b)
        result+=cost
print(result)
