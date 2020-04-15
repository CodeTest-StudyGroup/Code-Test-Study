def solution(N, number):
    answer = -1
    dp = []

    for i in range(8):
        temp = [(int(str(N) * (i + 1)))]
        if temp[0] == number:  # 연산 없이 바로 가능
            return i + 1
        else:
            for j in range(i):
                for first in dp[j]:
                    for second in dp[-j - 1]:  # j + -j -1을 이용, 제일 앞은 0 제일 뒤는 -1
                        for k in range(4):
                            try:
                                if k == 0:
                                    value = first + second
                                elif k == 1:
                                    value = first - second
                                elif k == 2:
                                    value = first * second
                                else:
                                    value = first // second

                                if value == number:
                                    return i + 1
                                else:
                                    temp.append(value)
                            except:
                                pass
            dp.append(temp)
    return answer


if __name__ == '__main__':
    result = solution(5, 12)
    print(result)
