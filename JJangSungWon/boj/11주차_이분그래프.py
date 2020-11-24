from collections import deque
import sys


def bfs(start):
    q = deque()
    q.append(start)
    bg[start] = 1  # 1구역 배정

    while q:
        v = q.popleft()
        for index in connect[v]:
            if bg[index] == -1:  # 아직 배정 x
                if bg[v] == 1:
                    bg[index] = 2
                elif bg[v] == 2:
                    bg[index] = 1
                q.append(index)
            elif bg[index] == bg[v]:
                return 0
    return 1


if __name__ == "__main__":
    k = int(sys.stdin.readline())
    for _ in range(k):
        v, e = map(int, sys.stdin.readline().split())  # 정점, 간선
        connect = [set() for _ in range(v + 1)]
        for _ in range(e):
            a, b = map(int, sys.stdin.readline().split())
            connect[a].add(b)
            connect[b].add(a)

        bg = [-1] * (v + 1)  # Bipartite Graph
        flag = True
        for i in range(1, v + 1):
            if bg[i] == -1:
                temp = bfs(i)
                if not temp:
                    flag = False
                    break

        if flag:
            print("YES")
        else:
            print("NO")
