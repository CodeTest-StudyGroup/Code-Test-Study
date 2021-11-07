import sys
input = sys.stdin.readline

n = int(input())

M = list(map(int, input().split()))
W = list(map(int, input().split()))

M.sort(key=lambda x : abs(x))
W.sort(key=lambda x : abs(x))

minus_M = []
plus_M = []

minus_W = []
plus_W = []

res = 0

for m, w in zip(M, W):
    if m < 0:
        minus_M.append(-m)
    else:
        plus_M.append(m)
    
    if w < 0:
        minus_W.append(-w)
    else:
        plus_W.append(w)

l_w = 0
u_m = 0
while l_w < len(minus_W) and u_m < len(plus_M):
    female = minus_W[l_w]
    male = plus_M[u_m]
    if male < female:
        res += 1
        u_m += 1
    l_w += 1

l_m = 0
u_w = 0
while l_m < len(minus_M) and u_w < len(plus_W):
    male = minus_M[l_m]
    female = plus_W[u_w]
    if male > female:
        res += 1
        u_w += 1
    l_m += 1

print(res)