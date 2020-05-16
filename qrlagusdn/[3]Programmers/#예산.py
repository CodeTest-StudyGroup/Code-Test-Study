#예산

def solution(budgets, M):
    answer = 0
    res = 0
    front, rear = 0,max(budgets)
    while 1:     
        if front>rear: break

        mid = (rear + front)//2
        tmp = 0
        for i in range(0,len(budgets)):
            if budgets[i] > mid:
                tmp += mid
            else:
                tmp += budgets[i]

        if tmp > M:
            rear = mid-1
        else:
            answer = mid
            front = mid+1

    return answer

if __name__ == "__main__":
    print(solution([120, 110, 140, 150],485))