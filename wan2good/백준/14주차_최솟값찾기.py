from collections import deque
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,l=MIS();data=list(MIS());q=deque()
for i in range(len(data)):
    while True:
        if q and q[-1][1]>data[i]: q.pop()
        else: break
    q.append((i,data[i]))

    while True:
        if q and q[0][0]<i-l+1: q.popleft()
        else: break
    print(q[0][1],end=' ')