import heapq
MIS=lambda:map(int,input().split())
n,k=MIS();q=[];C=[];result=0;q2=[]
for _ in range(n):
    m,v=MIS();heapq.heappush(q,(m,v))
C=[int(input()) for _ in range(k)];C.sort()
for bag in C:
    while q:
        if q[0][0]<=bag:m,v=heapq.heappop(q);heapq.heappush(q2,(-v,m))
        else:break
    if q2:v,m=heapq.heappop(q2);result-=v
print(result)