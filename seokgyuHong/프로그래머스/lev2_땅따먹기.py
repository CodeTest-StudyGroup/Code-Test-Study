def solution(land):
    answer = 0
    idx = -1
    for i in range(len(land)):
        max = 0
        temp = -1
        for j in range(4):
            if land[i][j] > max and j != idx:
                max = land[i][j]
                temp = j
        idx = temp
        answer += max

    return answer


print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]));