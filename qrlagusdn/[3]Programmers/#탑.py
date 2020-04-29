#탑
def solution(heights):
    answer = []
    for i in range(len(heights)-1,-1,-1):
        flag = -1
        for j in range(i-1,-1,-1):
            if heights[i] < heights[j]:
                flag = j
                break
        if flag != -1: flag += 1
        elif flag == -1: flag = 0
        answer.append(flag)
    answer = answer[::-1]
    return answer


if __name__ =="__main__":
    print(solution([2,1,1,1]))