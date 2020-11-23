import heapq
import sys

if __name__ == "__main__":
    k, n = map(int, sys.stdin.readline().split())
    p = list(map(int, sys.stdin.readline().split()))

    q = []
    for i in range(len(p)):
        heapq.heappush(q, p[i])

    for _ in range(n):
        num = heapq.heappop(q)
        for i in range(k):
            temp = num * p[i]
            heapq.heappush(q, temp)
            if num % p[i] == 0:
                break
    print(num)
