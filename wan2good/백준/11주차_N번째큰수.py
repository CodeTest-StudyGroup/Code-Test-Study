import heapq
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().split())
n=int(input().rstrip());q=[];data=[]
for _ in range(n):
    data.append(list(MIS()))
for num in data[n-1]:
    heapq.heappush(q,num)
for i in range(n-2,-1,-1):
    for j in range(n):
        if q[0]<data[i][j]:
            tmp=heapq.heappop(q);heapq.heappush(q,data[i][j])
print(heapq.heappop(q))