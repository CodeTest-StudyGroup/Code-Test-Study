import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

h,w=MIS()
block=list(MIS())

result=0
for idx in range(1,w-1):
    left,right=0,0
    for x in range(idx):
        left=max(left,block[x])
    for y in range(idx+1,w):
        right=max(right,block[y])
    
    if min(left,right)-block[idx]>0:
        result+=min(left,right)-block[idx]
print(result)