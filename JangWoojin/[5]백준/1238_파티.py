import sys
from heapq import heappush, heappop

input = sys.stdin.readline
INF = 1e9


def dijkstra(g, src, n):
    costs = [INF for _ in range(n + 1)]
    costs[src] = 0
    hq = [(costs[src], src)]
    while hq:
        c, v = heappop(hq)
        if costs[v] < c:
            continue
        for adj, cost in g[v]:
            if c + cost < costs[adj]:
                costs[adj] = c + cost
                heappush(hq, (costs[adj], adj))
    return costs[1:]


def solve():
    n, m, x = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    graph2 = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v, c = map(int, input().split())
        graph[u].append((v, c))
        graph2[v].append((u, c))

    print(max([a + b for a, b in zip(dijkstra(graph, x, n), dijkstra(graph2, x, n))]))


if __name__ == '__main__':
    solve()
