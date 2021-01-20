import sys
import collections
test = int(input())


for _ in range(test):
    n,m = map(int,sys.stdin.readline().rstrip().split())
    graph = [[] for _ in range(n+1)]
    queue = collections.deque()
    for i in range(m):
        a,b = map(int,sys.stdin.readline().rstrip().split())
        graph[a].append(b)
        graph[b].append(a)
    visited = [False]*(n+1)
    start = 1
    cnt =0
    queue.append(start)
    visited[start]=True
    while queue:
        cur = queue.popleft()
        for temp in graph[cur]:
            if visited[temp]==False:
                queue.append(temp)
                visited[temp] = True
                cnt+=1
    print(cnt)

