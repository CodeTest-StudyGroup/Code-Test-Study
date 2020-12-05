from heapq import heappush, heapreplace
import sys
input = sys.stdin.readline
n = int(input())
hq = []
for _ in range(n):
    arr = map(int, input().split())
    for x in arr:
        if len(hq) < n:
            heappush(hq, x)
        elif x > hq[0]:
            heapreplace(hq, x)
print(hq[0])
