from bisect import bisect_left


if __name__ == "__main__":
    n = int(input())  # 전깃줄의 개수
    connect = []
    max_index = -1
    for _ in range(n):
        a, b = map(int, input().split())
        connect.append((a, b))
        max_index = max(max_index, a)

    # A를 기준으로 오름차순 정렬
    connect.sort()
    selected = [connect[0][1]]  # 선택된 전깃줄
    dp = [1] * n

    for i in range(1, n):
        if selected[-1] < connect[i][1]:  # 추가 가능
            dp[i] = max(dp) + 1
            selected.append(connect[i][1])
        else:
            x = bisect_left(selected, connect[i][1])
            if connect[i][1] > selected[x]:  # 최댓값이 적으면 더 많은 전봇대를 설치할 수 있는 확률을 높일 수 있다.
                selected[-1] = connect[i][1]
            else:  # 바꾸는게 좋은 상황
                selected[x] = connect[i][1]
                dp[i] = x + 1

    remove_cnt = n - len(selected)
    selected_cnt = len(selected)
    print(remove_cnt)

    # selected를 실제 lis 인덱스로 변환해야한다(B -> A)
    index = []
    for i in range(n - 1, -1, -1):
        if selected_cnt == dp[i]:
            index.append(connect[i][0])
            selected_cnt -= 1

    for i in connect:
        if i[0] not in index:
            print(i[0])


