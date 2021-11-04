import math
import sys
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n = int(input())

star = [[0, 0]]
parent = list(range(n + 1))
edge = []

for _ in range(n):
    star.append(list(map(float, input().split())))

for i in range(1, n + 1):
    for j in range(i + 1, n + 1):        
        edge.append([round(math.sqrt((star[i][0]-star[j][0])**2 + (star[i][1]-star[j][1])**2), 2), i, j])

edge.sort()

res = 0
for e in edge:
    cost, a, b = e
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        res += cost
print(res)