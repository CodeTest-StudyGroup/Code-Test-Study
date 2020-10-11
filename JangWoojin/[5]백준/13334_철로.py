from heapq import heappop, heappush
n = int(input())
lines = []
for _ in range(n):
    h, o = map(int, input().split())
    lines.append((min(h, o), max(h, o)))
lines.sort(key=lambda x: x[1])
answer = 0
d = int(input())
hq = []
for line in lines:
    heappush(hq, line)
    while len(hq) and hq[0][0] < line[1] - d:
        heappop(hq)
    answer = max(answer, len(hq))
print(answer)
