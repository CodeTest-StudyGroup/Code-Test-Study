import heapq
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().split())
k,n=MIS();data=list(MIS());q=[];cnt=0
for item in data:
    heapq.heappush(q,item)
while cnt<n-1:
    cnt+=1;num=heapq.heappop(q)
    for prime in data:
        if num*prime<pow(2,31):
            heapq.heappush(q,num*prime)
    while num==q[0]:
        tmp=heapq.heappop(q)
print(q[0])