import sys
d,k=map(int,input().split())
dp=[0]*31;dp[1],dp[2]=1,1;x=1
for i in range(3,d+1):
    dp[i]=dp[i-2]+dp[i-1]
a=dp[d-2];b=dp[d-1]
while True:
    s=0;y=1;s+=a*x
    while True:
        s+=b*y
        if s>k:break
        if s==k:print(x);print(y);sys.exit()
        s-=b*y;y+=1
    x+=1