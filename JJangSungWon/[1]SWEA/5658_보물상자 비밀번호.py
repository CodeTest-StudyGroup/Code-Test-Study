def hexa_to_ten(array, side):
    result = 0
    for i in range(1, side + 1):
        if "0" <= array[-i] <= "9":
            result += int(array[-i]) * pow(16, i - 1)
        else:
            result += (ord(array[-i]) - 55) * pow(16, i - 1)
    return result


if __name__ == "__main__":
    for tc in range(1, int(input()) + 1):
        n, k = map(int, input().split())
        num = list(input().strip())
        answer = []

        # 한 변의 개수
        side = n // 4

        for i in range(side):
            for j in range(0, len(num), side):
                temp = num[j:j+side]
                answer.append(hexa_to_ten(temp, side))
            num = [num[-1]] + num[:-1]

        answer = list(set(answer))
        answer.sort(reverse=True)
        print("#{} {}".format(tc, answer[k - 1]))

