def solution(n, times):

    # 최소 0분, 최대: 제일 시간 많은 심사위원에게 모두 검사 받는 경우
    left, right = 0, max(times) * n
    answer = 0
    while left <= right:
        mid = (left + right) // 2

        possible = 0
        for i in times:
            possible += mid // i  # 해당 심사위원이 얼마나 검사할 수 있는지

        if possible >= n:  # n명 이상 가능한 경우 -> 더 작은 곳도 가능한지 파악해야 한다!
            answer = mid
            right = mid - 1
        elif possible < n:
            left = mid + 1
    return answer


if __name__ == "__main__":
    print(solution(6, [7, 10]))