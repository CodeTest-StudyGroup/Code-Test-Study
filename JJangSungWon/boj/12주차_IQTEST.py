if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))

    # 모든 수가 같으면 A 출력
    if n == 1:
        print("A")
    elif n == 2:
        if array[0] == array[1]:
            print(array[0])
        else:
            print("A")
    else:
        if array[1] - array[0] == 0:
            a = 0
            b = array[1]  # b = array[1] - array[0] * a이기 때문에
        else:
            a = (array[2] - array[1]) // (array[1] - array[0])
            b = array[1] - array[0] * a

        # a, b값이 패턴을 만족시키는지 확인
        flag = True
        for i in range(1, n):
            if array[i] == array[i - 1] * a + b:
                continue
            else:
                flag = False
                break

        if flag:
            print(array[n - 1] * a + b)
        else:
            print("B")