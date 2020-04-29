def solution(heights):
    # 제일 왼쪽 탑은 수신할 수 있는 탑이 존재하지 않는다.
    answer = [0]

    # i = 2
    for i in range(1, len(heights)):
        for j in range(i - 1, -1, -1):
            if heights[j] > heights[i]:
                answer.append(j + 1)
                break
            elif j == 0:
                answer.append(0)
    return answer


if __name__ == "__main__":
    print(solution([3,9,9,3,5,7,2]))

