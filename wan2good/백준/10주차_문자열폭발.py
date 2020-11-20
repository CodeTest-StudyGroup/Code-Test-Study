import sys;input=sys.stdin.readline
data=list(map(str,input().rstrip()))
boom=input().rstrip();s=[0]*1000000;idx=0
for c in data:
    s[idx]=c
    idx+=1
    boomIdx=len(boom)-1
    if boom[boomIdx]==c:
        check=False
        for i in range(idx-1,idx-len(boom)-1,-1):
            if s[i]==boom[boomIdx]:
                check=True
            else:
                check=False
                break
            boomIdx-=1
        if check:idx-=len(boom)

if idx==0:print('FRULA')
else:
    for i in range(idx):
        print(s[i],end='')