def solution(stones, k):
    answer = 0

    flag = 1
    value = 0

    while flag:
        temp = [i for i in range(len(stones)) if stones[i] <= value]

        if len(temp) == 0:
            answer += 1
            value += 1
        else:
            if k == 1:
                flag = 0
                break

            if len(temp) >= k-1:
                cnt = 0
                for i in range(len(temp) - 1):
                    if temp[i] == temp[i+1] - 1:
                        cnt += 1
                        if cnt == k - 1:
                            flag = 0
                            break
                    else:
                        cnt = 0

            if flag == 1:
                answer += 1
                value += 1

    return answer


if __name__ == "__main__":
    print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))
