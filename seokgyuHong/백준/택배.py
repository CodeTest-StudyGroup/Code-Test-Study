import sys

n,c = map(int,input().split())
m = int(input())

arr = []

for _ in range(m):
    start,end,size = map(int,sys.stdin.readline().rstrip().split())
    arr.append((start,end,size))


arr = sorted(arr,key=lambda x:x[1])
truck = [c]*n
cnt=0
for i in range(m):
    start = arr[i][0]
    end = arr[i][1] #도착지점
    min_val = min(truck[start:end])
    if min_val==0:
        continue

    elif min_val>=arr[i][2]:
        for j in range(start,end):
            truck[j]-=arr[i][2]
        cnt+=arr[i][2]
    else:
        for j in range(start,end):
            truck[j]-=min_val
        cnt+=min_val

print(cnt)






