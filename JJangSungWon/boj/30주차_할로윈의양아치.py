from collections import defaultdict, deque
import sys


def bfs(idx):
    q = deque()
    q.append(idx)
    cnt, weight = 1, candy[idx - 1]
    visited[idx] = True
    while q:
        idx = q.popleft()
        for next_index in friend[idx]:
            if visited[next_index] is False:
                q.append(next_index)
                cnt += 1
                weight += candy[next_index - 1]
                visited[next_index] = True
    return cnt, weight


if __name__ == "__main__":
    # 입력
    n, m, k = map(int, sys.stdin.readline().split())
    candy = list(map(int, sys.stdin.readline().split()))
    friend = defaultdict(list)
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        friend[a].append(b)
        friend[b].append(a)

    # 친구 관계 형성
    group = dict()
    index = 0
    visited = [False] * (n + 1)
    for i in range(1, n + 1):
        if visited[i] is False:
            cnt, weight = bfs(i)
            group[index] = [cnt, weight]
            index += 1

    # dp = [[0] * k for _ in range(len(group))]  # dp[i][j] : i번째 친구 그룹까지 확인, 공간 j안에 넣을 수 있는 최대 사탕
    dp = [0] * k
    for i in range(len(group)):
        for j in range(k - 1, 0, -1):
            if j - group[i][0] >= 0:
                dp[j] = max(dp[j], dp[j - group[i][0]] + group[i][1])
    print(dp[-1])
