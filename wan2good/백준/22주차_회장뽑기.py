import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n=int(input().rstrip())
graph=[[2e10 for _ in range(n+1)] for _ in range(n+1)]
while True:
    a,b=MIS()
    if a==-1 and b==-1: break
    graph[a][b]=1
    graph[b][a]=1

for i in range(1,n+1):
    graph[i][i]=0

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])

score=2e10;arr=[]
for i in range(1,n+1):
    tmp=max(graph[i][1:])
    arr.append(tmp)
    score=min(score,tmp)

result=[]
for i in range(len(arr)):
    if arr[i]==score:
        result.append(i+1)

print(score,len(result))
for num in result:
    print(num,end=' ')