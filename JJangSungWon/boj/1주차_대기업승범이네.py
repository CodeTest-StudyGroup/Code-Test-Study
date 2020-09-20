import sys

sys.setrecursionlimit(10 ** 9)


def dfs(current_index, pre_index):
    sub_total = 0
    child = []
    for next_index in graph[current_index]:
        dfs(next_index, current_index)
        dp[current_index][0] += max(dp[next_index][0], dp[next_index][1])
        sub_total += max(dp[next_index][0], dp[next_index][1])
        # 더 좋은 형태의 child 삽입
        if dp[next_index][1] > dp[next_index][0]:
            child.append([next_index, 1])
        else:
            child.append([next_index, 0])

    for i in range(len(child)):
        chd = child[i][0]
        flag = child[i][1]
        if flag == 1:  # 바꿔서 실행해보고 더 좋으면 교체한다.
            temp = sub_total - dp[chd][1] + dp[chd][0]
            temp += cost[chd] * cost[current_index]
            if temp > dp[current_index][1]:
                dp[current_index][1] = temp
        else:
            dp[current_index][1] = max(dp[current_index][1], sub_total + cost[chd] * cost[current_index])


if __name__ == "__main__":
    n = int(input())  # 판매원들의 수
    connect = list(map(int, input().split()))  # 사수 관계
    cost = [0] + list(map(int, input().split()))  # 판매원의 실력

    # 관계 연결
    graph = [[] for _ in range(n + 1)]
    for i in range(n - 1):
        graph[connect[i]].append(i + 2)

    dp = [[0, 0] for _ in range(n + 1)]  # 합, 멘토 플래그

    dfs(1, None)

    print(max(dp[1][0], dp[1][1]))