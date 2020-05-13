def solution(citations):
    answer = 0

    citations.sort()
    while True:
        cnt = 0

        for i in range(len(citations)):
            if citations[i] >= answer:
                cnt += 1

        if cnt >= answer:
            answer += 1
        else:
            break

    return answer - 1


if __name__ == "__main__":
    print(solution([3, 0, 6, 1, 5]))
