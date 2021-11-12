import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())

indegree = [0] * (n + 1) # 간선 정보

edge = [[] for _ in range(n + 1)] # 연결 그래프 초기화

for _ in range(m):
    x, y, k = map(int, input().split()) # y부품 k개가 -> x가 됨
    
    indegree[x] += 1 # 간선 개수 추가
    edge[y].append((x, k))

lines = [[0] * (n + 1) for _ in range(n+1)] # 각 기본 부품이 몇 개 있는지 (n개로 뒀지만 어차피 다음 코드에 기본 부품밖에 안 셈)

for i in range(1, n + 1):
    if indegree[i] == 0: # 간선이 처음에 없으면 기본부품이다.
        lines[i][i] += 1 # 기본부품은 자기 자신의 개수 1로 설정.

q = deque() # 양방향 처리를 위해 deque사용.

for j in range(1, n + 1):
    if indegree[j] == 0: # 간선이 없는 부품은 q에 넣어준다.
        q.append(j)

while q:
    now = q.popleft() # 현재 부품

    # 그 부품이랑 연결된 중간 부품들 간선개수 줄이고, 부품개수 업데이트
    for i in edge[now]:
        next, cost = i
        indegree[next] -= 1

        # 다음 부품의 간선이 없어지면 q에 넣음
        if indegree[next] == 0:
            q.append(next)
        # 다음 부품의 부품개수 = 현재 부품 * 이뤄지는 개수
        for j in range(1, n + 1):
            lines[next][j] += lines[now][j] * cost

# 완제품의 부품들을 enumerate로 돌면서 0개 이상이면 부품 번호와 개수 출력
for a, b in enumerate(lines[n]):
    if b > 0:
        print(a, b)