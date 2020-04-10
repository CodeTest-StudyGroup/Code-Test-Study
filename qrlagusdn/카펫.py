def solution(brown, red):
    answer = []
    for i in range(1,red+1):
        if red % i == 0:
            a = i
            b = red//i
            if (a+b+2)*2 == brown:
                answer = [b+2, a+2]
                break
    return answer

if __name__ == "__main__":
    # a*b = red0
    # 2(a+b+2) = brown
    brown, red = map(int,input().split())
    ans = solution(brown, red)
    print(ans)