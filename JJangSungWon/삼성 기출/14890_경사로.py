if __name__ == "__main__":
    n, l = map(int, input().split())
    array = [list(map(int, input().split())) for _ in range(n)]

    # 가로 확인
    answer = 0
    for i in range(n):
        value = array[i][0]  # 낮은 층의 값
        cnt = 1  # 높이가 낮은 층의 연속된 갯수
        check = True
        for j in range(1, n):
            if abs(array[i][j] - value) >= 2:
                break
            if check:
                if array[i][j] == value:
                    cnt += 1
                elif array[i][j] > value:
                    if cnt >= l:
                        value = array[i][j]
                        cnt = 1
                    else:
                        check = False
                        break
                else:
                    if j + l - 1 < n:
                        current_value = array[i][j]
                        if l == 1:
                            value = array[i][j]
                            cnt = 0
                        else:
                            for k in range(j + 1, j + l):
                                if array[i][k] != current_value:
                                    check = False
                                    break
                                elif k == j + l - 1:
                                    value = array[i][k]
                                    cnt = -l + 1
                    else:
                        check = False
                        break
            else:
                check = False
                break
            if j == n - 1 and check:
                answer += 1

    # 세로 확인
    for i in range(n):
        check = True
        value = array[0][i]
        cnt = 1
        for j in range(1, n):
            if abs(array[j][i] - value) >= 2:
                break
            if check:
                if array[j][i] == value:
                    cnt += 1
                elif array[j][i] > value:
                    if cnt >= l:
                        value = array[j][i]
                        cnt = 1
                    else:
                        check = False
                        break
                else:
                    if j + l - 1 < n:
                        current_value = array[j][i]
                        if l == 1:
                            value = array[j][i]
                            cnt = 0
                        else:
                            for k in range(j + 1, j + l):
                                if array[k][i] != current_value:
                                    check = False
                                    break
                                elif k == j + l - 1:
                                    value = array[k][i]
                                    cnt = -l + 1
                    else:
                        check = False
                        break
            else:
                check = False
                break
            if j == n - 1 and check:
                answer += 1

    print(answer)