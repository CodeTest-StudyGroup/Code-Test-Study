from collections import deque
n=int(input());data=[]
for _ in range(n):
    data.append(int(input()))
tmp=[];plus=[];other=[]
for item in data:
    if item>0: plus.append(item)
    else: other.append(item)

result=[]
plus.sort(reverse=True)
other.sort()
while True:
    plus=deque(plus)
    if len(plus)>2:
        a,b=plus.popleft(),plus.popleft()
        if a*b>a+b: result.append(a*b)
        else: result.append(a);result.append(b)
    else:
        if len(plus)==2:
            a,b=plus.popleft(),plus.popleft()
            if a*b>a+b: result.append(a*b)
            else: result.append(a);result.append(b)
            break
        else:
            for item in plus:
                result.append(item)
            break

while True:
    other=deque(other)
    if len(other)>2:
        a,b=other.popleft(),other.popleft()
        result.append(a*b)
    else:
        if len(other)==2:
            a,b=other.popleft(),other.popleft()
            result.append(a*b)
            break
        else:
            for item in other:
                result.append(item)
            break
value=0
for item in result:
    value+=item
print(value)