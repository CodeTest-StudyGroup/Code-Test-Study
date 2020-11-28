import sys
from heapq import heappush, heappop, heapify
input = sys.stdin.readline
k, n = map(int, input().split())
primes = list(map(int, input().split()))
hq = primes.copy()
heapify(hq)
num = 0
for _ in range(n):
    num = heappop(hq)
    for prime in primes:
        heappush(hq, prime * num)
        if num % prime == 0:
            break
print(num)
