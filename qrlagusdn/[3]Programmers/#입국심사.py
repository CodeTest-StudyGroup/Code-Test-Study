#입국심사

#넘어려운뎅...,?

def solution(n, times):
    answer = []
    high = max(times) * n
    low = 0
    answer = 99999999999999999
    while 1:
        if high-low==1: break
        mid = (high+low)//2
        tmp = 0
        for t in times:
            tmp += mid//t

        if tmp>=n:
            high = mid
            answer = min(answer,mid)
        else:
            low = mid
    
    return answer
    
if __name__ == "__main__":

    print(solution(6,[7, 10]	))
