import sys
from heapq import heappush, heappop
input = sys.stdin.readline

n, k = map(int, input().split())
jewelry = []
napsack = []
for _ in range(n):
    jewelry.append(tuple(map(int, input().split())))
for _ in range(k):
    napsack.append(int(input()))

jewelry = sorted(jewelry)
napsack = sorted(napsack)

answer = 0
hq = []
i = 0
for weight in napsack:
    while i < n and jewelry[i][0] <= weight:
        heappush(hq, -jewelry[i][1])
        i += 1
    if hq:
        answer += -heappop(hq)

print(answer)
