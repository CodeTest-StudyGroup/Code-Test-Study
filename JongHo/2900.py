import sys
input = sys.stdin.readline

n, k = map(int, input().split())

a = [0] * n
num = [0] * n
m = list(map(int, input().split()))
q = int(input())

for i in m:
    num[i] += 1

for i in range(n):
    if num[i] != 0:
        for j in range(0, n, i):
            a[j] += num[i]
a[0] = k

for i in range(1, len(a)):
    a[i] += a[i - 1]
a = [0] + a

for _ in range(q):
    l, r = map(int, input().split())
    print(a[r+1] - a[l])