def num_to_n(num, n):  # num을 n진법 수로 변환
    result = ""
    if num == 0:
        return ['0']
    while num > 0:
        value = num % n
        if value >= 10:
            if value == 10:
                result += "A"
            elif value == 11:
                result += "B"
            elif value == 12:
                result += "C"
            elif value == 13:
                result += "D"
            elif value == 14:
                result += "E"
            else:
                result += "F"
        else:
            result += str(value)
        num //= n
    result = list(result)
    result.reverse()
    return result


def solution(n, t, m, p):
    answer = []
    for i in range(m * (t - 1) + p):
        answer.extend(num_to_n(i, n))

    answer = "".join(map(str, answer))
    result = ""
    for i in range(len(answer)):
        if i % m == p - 1:
            result += answer[i]
        if len(result) == t:
            break
    return result


if __name__ == "__main__":
    print(solution(2, 4, 2, 1))