input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,c=MIS();m=int(input().rstrip());data=[]
for _ in range(m):
    data.append(list(MIS()))
data=sorted(data,key=lambda x: (x[1],x[0]))

truck=[c]*(n+1)
result=0
for i in range(len(data)):
    a,b,cost=data[i]
    minV=c
    for idx in range(a,b):
        minV=min(minV,truck[idx])
    if minV>cost:
        result+=cost
        for idx in range(a,b):
            truck[idx]-=cost
    else:
        result+=minV
        for idx in range(a,b):
            truck[idx]-=minV
print(result)