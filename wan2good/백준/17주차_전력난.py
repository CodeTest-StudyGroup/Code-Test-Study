def find_parent(parent,x):
    if parent[x]!=x: parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b: parent[b]=a
    else: parent[a]=b

input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
while True:
    m,n=MIS()
    if m==0 and n==0: break
    graph=[[] for _ in range(m+1)]

    parent=[0]*(n+1)
    for i in range(1,n+1):
        parent[i]=i

    edges=[]
    for _ in range(n):
        a,b,c=MIS()
        edges.append((c,a,b))
    edges.sort()

    result=0;total=0
    for cost,a,b in edges:
        total+=cost
        if find_parent(parent,a)!=find_parent(parent,b):
            result+=cost
            union_parent(parent,a,b)
    print(total-result)