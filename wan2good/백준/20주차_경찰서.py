import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip())
cost=[0]+list(MIS())
board=[]
for _ in range(n):
    board.append(list(map(int,input().rstrip())))

graph=[[] for _ in range(n+1)]
re_graph=[[] for _ in range(n+1)]
for i in range(n):
    for j in range(n):
        if board[i][j]==1:
            graph[i+1].append(j+1)
            re_graph[j+1].append(i+1)

visited=[False]*(n+1)
stack=[]
def dfs(i):
    if visited[i]:
        return
    
    visited[i]=True
    for nextNode in graph[i]:
        dfs(nextNode)
    stack.append(i)
    return

scc=[0]*(n+1)
re_visited=[False]*(n+1)
def reverseDFS(i,idx):
    if re_visited[i]:
        return

    re_visited[i]=True
    scc[i]=idx
    for nextNode in re_graph[i]:
        reverseDFS(nextNode,idx)
    return

for i in range(1,n+1):
    dfs(i)

idx=0
while stack:
    if not re_visited[stack[-1]]:
        reverseDFS(stack[-1],idx)
        idx+=1
    stack.pop()

check=[False]*(n+1)
result=0
for i in range(1,n+1):
    SCC=[]
    if check[scc[i]]: continue
    check[scc[i]]=True
    for j in range(1,n+1):
        if scc[i]==scc[j]: SCC.append(j)
    minV=2e10
    for i in SCC:
        minV=min(minV,cost[i])
    result+=minV

print(result)
