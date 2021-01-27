import sys
from collections import deque
n=int(input())

if 0<=n<10: print(n)
else:
    q=deque(list(range(1,10)))
    cnt=9
    while cnt<n:
        num=q.popleft()
        if num==9876543210: print(-1);sys.exit()
        tmp=num%10
        for i in range(tmp):
            q.append(num*10+i)
            cnt+=1
            if cnt==n: print(num*10+i);break