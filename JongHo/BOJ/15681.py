import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def makeTree(current, p):
    for node in graph[current]:
        if node != p:
            child[current].append(node)
            parent[node] = current
            makeTree(node, current)

def countSubtreeNodes(current):
    size[current] = 1
    for node in child[current]:
        countSubtreeNodes(node)
        size[current] += size[node]

n, r, q = map(int, input().split())

graph = [[] for _ in range(n + 1)]
parent = [x for x in range(n + 1)]
child = [[] for _ in range(n + 1)]
size = [0 for _ in range(n + 1)]

for _ in range(n - 1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

makeTree(r, -1)
countSubtreeNodes(r)
for _ in range(q):
    print(size[int(input())])