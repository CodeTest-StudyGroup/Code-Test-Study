input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip())
x,y=0,0;result=0
for _ in range(n):
    tmpx,tmpy=MIS()
    if x==0 and y==0: x,y=tmpx,tmpy
    else:
        if x<=tmpx<=y and x<=tmpy<=y: continue
        elif x<=tmpx<=y and not x<=tmpy<=y: y=tmpy
        elif not x<=tmpx<=y and x<=tmpy<=y: x=tmpx
        else: result+=y-x;x,y=tmpx,tmpy
print(result+y-x)