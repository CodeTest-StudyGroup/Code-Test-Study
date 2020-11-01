if __name__ == "__main__":
    n = int(input())
    answer = []
    k = 0
    # 비트 활용
    while n:
        if n % 2 != 0:
            answer.append('/')  # 제일 오른쪽 비트를 0으로 만든다.
            n *= 2
        elif n & 2 != 0:
            answer.append('+')  # 제일 오른쪽 앞 비트를 0으로 만든다.
            n -= 2
        else:
            answer.append('*')  # 한칸씩 당긴다.
            n //= 2
        k += 1

    # 출력
    if k > 100:
        print(-1)
    else:
        print(k)
        for i in range(len(answer) - 1, -1, -1):
            if i == 0:
                print("[{}]".format(answer[i]))
            else:
                print("[{}]".format(answer[i]), end=" ")