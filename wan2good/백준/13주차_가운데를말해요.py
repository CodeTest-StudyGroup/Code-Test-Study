import heapq
input=__import__('sys').stdin.readline
n=int(input().rstrip())
max_h=[];min_h=[]
for _ in range(n):
    num=int(input().rstrip())
    if len(max_h)==0: heapq.heappush(max_h,-num)
    else:
        if len(max_h)>len(min_h): heapq.heappush(min_h,num)
        else: heapq.heappush(max_h,-num)
        if -max_h[0]>min_h[0]:
            tmp1,tmp2=heapq.heappop(max_h),heapq.heappop(min_h)
            heapq.heappush(min_h,-tmp1);heapq.heappush(max_h,-tmp2)
    print(-max_h[0])