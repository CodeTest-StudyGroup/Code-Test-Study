
answer = 0


def dfs(cnt, result, numbers, target):
    global answer
    if cnt == len(numbers):
        if result == target:
            answer += 1
        return

    for i in range(2):
        if i == 0:
            if cnt == 0 or (cnt != 0 and result + sum(numbers[cnt:]) >= target):
                dfs(cnt + 1, result + numbers[cnt], numbers, target)
        else:
            if cnt == 0 or (cnt != 0 and result - sum(numbers[cnt:]) <= target):
                dfs(cnt + 1, result - numbers[cnt], numbers, target)


def solution(numbers, target):
    dfs(0, 0, numbers, target)
    return answer


if __name__ == "__main__":
    max_cnt = 0
    numbers = [1, 1, 1, 1, 1]
    target = 3

    print(solution(numbers, target))
