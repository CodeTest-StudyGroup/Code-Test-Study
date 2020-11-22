input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().split())
n=int(input());m=int(input());board=[];parent=[0]*(n+1)
for _ in range(n):
    board.append(list(MIS()))
plan=list(MIS())

def find_parent(parent,x):
    if parent[x]!=x:parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a=find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b:parent[b]=a
    else:parent[a]=b

for i in range(1,n+1):
    parent[i]=i

for i in range(len(board)):
    for j in range(len(board[i])):
        if board[i][j]==1:
            union_parent(parent,i+1,j+1)
node=0;flag=False
for i in plan:
    if not node:
        node=find_parent(parent,i)
    else:
        if find_parent(parent,i)!=node:
            flag=True;break
print('NO' if flag else 'YES')