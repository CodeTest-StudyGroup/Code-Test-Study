import sys
sys.setrecursionlimit(10**9)


def dfs(start):
    visited[start] = True
    dp[start][0] = people[start]  # 해당 인덱스를 선택
    for index in graph[start]:
        if not visited[index]:
            dfs(index)  # index를 방문한다.
            dp[start][0] += dp[index][1]  # 연결된 마을이 선택 안된 경우
            dp[start][1] += max(dp[index][0], dp[index][1])  # 현재 마을 선택안하는 경우


if __name__ == "__main__":
    n = int(input())  # 마을의 개수
    people = [0] + list(map(int, input().split()))

    # 연결 테이블 초기화
    graph = [[] for _ in range(n + 1)]

    for _ in range(n - 1):
        a, b = map(int, input().split())
        # 양방향
        graph[a].append(b)
        graph[b].append(a)

    dp = [[0] * 2 for _ in range(n + 1)]  # (선택 플래그, 인구 합)
    visited = [False] * (n + 1)  # 방문 리스트

    dfs(n - 1)

    answer = 0
    for i in range(1, n + 1):
        answer = max(answer, max(dp[i]))
    print(answer)








