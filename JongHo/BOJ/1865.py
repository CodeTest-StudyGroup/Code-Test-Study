import sys
input = sys.stdin.readline

INF = int(2e9)

def bf(start):
    dist[start] = 0
    for i in range(n):
        for j in range(len(edge)):
            cur = edge[j][0]
            next = edge[j][1]
            cost = edge[j][2]
            if dist[next] > dist[cur] + cost: # 모든 간선에 대해서 거리 갱신
                dist[next] = dist[cur] + cost
                if i == n - 1: # 음수 사이클이 있을경우 true반환
                    return True
    return False


T = int(input())

for _  in range(T):
    n, m, w = map(int, input().split())
    edge = []
    flag = True

    for _ in range(m):
        s, e, t = map(int, input().split())
        edge.append([s, e, t])
        edge.append([e, s, t])
    
    for _ in range(w):
        s, e, t = map(int, input().split())
        edge.append([s, e, -t])
    dist = [INF] * (n + 1)
    negative = bf(1)

    if negative or dist[1] < 0:
        print("YES")
    else:
        print("NO")