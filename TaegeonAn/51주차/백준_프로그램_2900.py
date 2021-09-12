import sys
N, K = map(int, sys.stdin.readline().split())
x = list(map(int, sys.stdin.readline().split()))
q = int(sys.stdin.readline())
a = [0 for _ in range(N)]
jump_cnt = [0 for _ in range(N)]

for c in x:
    jump_cnt[c] += 1

for i in range(N):
    if jump_cnt[i] != 0:
        for j in range(0, N, i):
            a[j] += jump_cnt[i]

a[0] = K
for i in range(N-1):
    a[i+1] += a[i]
    
a = [0] + a
for _ in range(q):
    l, r = map(int, sys.stdin.readline().split())
    print(a[r+1] - a[l])


    
    