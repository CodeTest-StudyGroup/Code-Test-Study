import sys
input = sys.stdin.readline

flowers = []
n = int(input().rstrip())

def toDate(m,d):
    return m*100+d

for _ in range(n):
    m1,d1,m2,d2 = map(int,input().rstrip().split())
    flowers.append((toDate(m1,d1),toDate(m2,d2)))

flowers = sorted(flowers,key = lambda x : x[0])

start = toDate(3,1)
end = toDate(11,30)
idx = 0
temp = []
count = 0

while idx<n:
    if start>end:
        break
    for i in range(idx,n):
        if flowers[i][0] <= start and flowers[i][1] > start:
            temp.append(flowers[i][1])
            idx = i+1

    if temp:
        start = max(temp)
        temp = []
        count+=1
    else:
        break

if start>end:
    print(count)
else:
    print(0)
