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

n, m = map(int, input().split())

graph = []
parent = [x for x in range(n + 1)]

for _ in range(m + 1):
    a, b, c = map(int, input().split())
    if c == 0: # 오르막길
        graph.append((1, a, b))
    else:
        graph.append((0, a, b))

# 최솟값 구하기
graph.sort()
Min = 0

for edge in graph:
    c, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        Min += c

# 최댓값 구하기
parent = [x for x in range(n + 1)]
Max = 0
graph.sort(reverse = True)
for edge in graph:
    c, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        Max += c

# A^2 - B^2 = (A + B)(A - B) 이용. (단, A >= B)
print((Max + Min) * (Max - Min))