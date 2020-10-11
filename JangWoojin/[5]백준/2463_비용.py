import sys
input = sys.stdin.readline


def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]


def merge(u, v):
    parent[v] = u
    size[u] += size[v]
    size[v] = 1


n, m = map(int, input().split())
parent = [i for i in range(n+1)]
size = [1 for _ in range(n+1)]
total = 0
arr = []
for _ in range(m):
    x, y, w = map(int, input().split())
    total += w
    arr.append((x, y, w))

arr.sort(key=lambda x: x[2], reverse=True)

answer = 0
for u, v, w in arr:
    pu, pv = find(u), find(v)
    if pu != pv:
        answer += size[pu] * size[pv] * total
        merge(pu, pv)
    total -= w
answer %= 10**9
print(answer)
