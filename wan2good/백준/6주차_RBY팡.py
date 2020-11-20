import sys;input=sys.stdin.readline
n=int(input().rstrip());balls=[]
for _ in range(n):
    balls.append(int(input().rstrip()))
ans=-2e10
def cnt(i,j):
    left=i;right=i
    color=balls[i];balls[i]=j
    now,result=0,0

    while 0<=left and right<n and balls[left]==balls[right]:
        now=balls[left];tmp=0
        while 0<=left and balls[left]==now:
            left-=1;tmp+=1
        while right<n and balls[right]==now:
            right+=1;tmp+=1
        if tmp>=4:result += tmp
    balls[i]=color
    return result-1
for i in range(n):
    for j in range(1,4):
        ans=max(ans,cnt(i,j))
print(n-ans)