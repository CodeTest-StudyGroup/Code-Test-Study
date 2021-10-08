from itertools import combinations

n, m = map(int, input().split())
w = list(map(int, input().split()))
w2 = combinations(w, 2)

# 전처리.
for i in w2:
    if i[0] + i[1] <= n:
        w.append(i[0] + i[1])
w = list(set(w))

zzazang = [20000] * (n + 1)
zzazang[0] = 0

for i in w:
    for j in range(i, n + 1):
        zzazang[j] = min(zzazang[j], zzazang[j - i] + 1)

print(zzazang[n] if zzazang[n] != 20000 else -1)