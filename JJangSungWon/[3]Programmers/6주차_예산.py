def solution(budgets, M):

    left, right = min(budgets), max(budgets)

    answer = 0
    while left <= right:
        mid = (left + right) // 2

        total = 0
        for i in range(len(budgets)):
            if budgets[i] < mid:
                total += budgets[i]
            else:
                total += mid

        if total <= M:
            answer = mid
            left = mid + 1
        else:
            right = mid - 1

    if answer == 0:
        return M // len(budgets)
    else:
        return answer


if __name__ == "__main__":
    print(solution([9, 8, 5, 6, 7], 5))