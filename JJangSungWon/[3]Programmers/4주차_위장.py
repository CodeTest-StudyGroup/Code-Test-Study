def solution(clothes):
    temp = []

    for i in range(len(clothes)):
        if len(temp) == 0:
            temp.append([clothes[i][1], clothes[i][0]])
        else:
            flag = 1
            for j in range(len(temp)):
                if clothes[i][1] == temp[j][0]:
                    temp[j].append(clothes[i][0])
                    flag = 0

            if flag == 1:
                temp.append([clothes[i][1], clothes[i][0]])

    answer = 1
    for i in range(len(temp)):
        answer *= len(temp[i])  # 경우의 수에 안쓰는 것도 포함

    answer -= 1  # 모두 안 쓴 경우는 존재하지 않기 때문에 1을 빼준다
    return answer


if __name__ == "__main__":
    print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
