import sys

sys.setrecursionlimit(10 ** 9)


def find(array, flag):  # 타일로 가득 찬 경우가 있는지 확인
    global score
    result = False
    if flag == "G":  # 초록색 타일
        for i in range(6):
            flag = True  # 모두 꽉찬 상황이라고 가정
            for j in range(4):
                if array[i][j] is None:
                    flag = False
                    break
            if flag:  # 꽉찬 상황
                result = True
                score += 1
                for k in range(4):
                    if array[i][k] in [None, 0, 1, -1]:
                        array[i][k] = None
                    elif array[i][k] == 2:
                        array[i][k] = None
                        array[i + 1][k] = 0
                    elif array[i][k] == -2:
                        array[i][k] = None
                        array[i - 1][k] = 0
    else:
        for j in range(6):
            flag = True  # 모두 꽉찬 상황이라고 가정
            for i in range(4):
                if array[i][j] is None:
                    flag = False
                    break
            if flag:  # 꽉찬 상황
                result = True
                score += 1
                for k in range(4):
                    if array[k][j] in [None, 0, 2, -2]:
                        array[k][j] = None
                    elif array[k][j] == 1:
                        array[k][j] = None
                        array[k][j + 1] = 0
                    elif array[k][j] == -1:
                        array[k][j] = None
                        array[k][j - 1] = 0
    return result


def delete(array, flag):  # 마지막 행 or 열 삭제
    if flag == "G":  # 초록색 타일
        for i in range(4):
            if array[5][i] in [None, 0, 1, -1]:
                array[5][i] = None
            elif array[5][i] == -2:  # 1개로 분해
                array[5][i] = None
                array[4][i] = 0
    else:
        for i in range(4):
            if array[i][5] in [None, 0, 2, -2]:
                array[i][5] = None
            elif array[i][5] == -1:  # 1개로 분해
                array[i][5] = None
                array[i][4] = 0


def sorting(array, flag):  # 빈공간이 있는 경우 아래로 옮긴다.
    result_flag = False
    if flag == "G":  # 초록색 타일
        for i in range(4, -1, -1):
            for j in range(4):
                if array[i][j] is None:
                    continue
                if array[i][j] == 0 and array[i + 1][j] is None:
                    result_flag = True
                    array[i][j] = None
                    array[i + 1][j] = 0
                elif array[i][j] == 1 and array[i + 1][j] is None and array[i + 1][j + 1] is None:
                    result_flag = True
                    array[i][j] = None
                    array[i][j + 1] = None
                    array[i + 1][j] = 1
                    array[i + 1][j + 1] = -1
                elif array[i][j] == -2 and array[i + 1][j] is None:
                    result_flag = True
                    array[i - 1][j] = None
                    array[i][j] = 2
                    array[i + 1][j] = -2
    else:
        for j in range(4, -1, -1):
            for i in range(4):
                if array[i][j] is None:
                    continue
                if array[i][j] == 0 and array[i][j + 1] is None:
                    result_flag = True
                    array[i][j] = None
                    array[i][j + 1] = 0
                elif array[i][j] == -1 and array[i][j + 1] is None:
                    result_flag = True
                    array[i][j - 1] = None
                    array[i][j] = 1
                    array[i][j + 1] = -1
                elif array[i][j] == 2 and array[i][j + 1] is None and array[i + 1][j + 1] is None:
                    result_flag = True
                    array[i][j] = None
                    array[i + 1][j] = None
                    array[i][j + 1] = 2
                    array[i + 1][j + 1] = -2
    return result_flag


def solve(green, blue, data):
    x, y = data[1], data[2]
    if data[0] == 1:  # 1 x 1
        # 초록색 타일에 놓기
        pre = 0
        for i in range(6):
            if green[i][y] is None:
                pre = i
            else:
                break
        green[pre][y] = 0  # 1칸으로 구성

        # 파란색 타일에 놓기
        pre = 0
        for i in range(6):
            if blue[x][i] is None:
                pre = i
            else:
                break
        blue[x][pre] = 0  # 1칸으로 구성
    elif data[0] == 2:  # 1 x 2
        # 초록색 타일에 놓기
        pre = 0
        for i in range(6):
            if green[i][y] is None and green[i][y + 1] is None:
                pre = i
            else:
                break
        green[pre][y] = 1
        green[pre][y + 1] = -1

        # 파란색 타일에 놓기
        pre = 0
        for i in range(2, 6):
            if blue[x][i] is None:
                pre = i - 1
            else:
                break
        blue[x][pre] = 1
        blue[x][pre + 1] = -1
    else:  # 2 x 1
        # 초록색 타일에 놓기
        pre = 0
        for i in range(2, 6):
            if green[i][y] is None:
                pre = i - 1
            else:
                break
        green[pre][y] = 2
        green[pre + 1][y] = -2

        # 파란색 타일에 놓기
        pre = 0
        for i in range(6):
            if blue[x][i] is None and blue[x + 1][i] is None:
                pre = i
            else:
                break
        blue[x][pre] = 2
        blue[x + 1][pre] = -2

    while True:
        # 꽉 찬 행 열이 있는지 확인
        a = find(green, "G")
        b = find(blue, "B")

        if not a and not b:
            pass
        else:
            # 빈공간 관리
            while True:
                while True:
                    if not sorting(green, "G"):
                        break
                while True:
                    if not sorting(blue, "B"):
                        break

                # 꽉 찬 행 열이 있는지 확인
                a = find(green, "G")
                b = find(blue, "B")

                if not a and not b:
                    break

        # 초록색 0 ~ 1 행 확인
        g_cnt = 0
        for i in range(2):
            for j in range(4):
                if green[i][j] is not None:
                    g_cnt += 1
                    break

        if g_cnt > 0:
            for _ in range(g_cnt):
                delete(green, "G")
            while True:
                if not sorting(green, "G"):
                    break

        # 파란색 0 ~ 1 행 확인
        b_cnt = 0
        for j in range(2):
            for i in range(4):
                if blue[i][j] is not None:
                    b_cnt += 1
                    break
        if b_cnt > 0:
            for _ in range(b_cnt):
                delete(blue, "B")
            while True:
                if not sorting(blue, "B"):
                    break

        if g_cnt == 0 and b_cnt == 0:
            break


def tile_count(array, flag):  # 타일이 들어있는 칸의 개수 카운트
    count = 0
    if flag == "G":
        for i in range(6):
            for j in range(4):
                if array[i][j] is not None:
                    count += 1
    else:
        for i in range(4):
            for j in range(6):
                if array[i][j] is not None:
                    count += 1
    return count


if __name__ == "__main__":
    n = int(input())  # 블록을 놓은 횟수

    # 보드 초기화
    green = [[None] * 4 for _ in range(6)]
    blue = [[None] * 6 for _ in range(4)]

    # 블록을 하나씩 놓는다.
    score = 0
    for i in range(n):
        t, x, y = map(int, input().split())
        solve(green, blue, (t, x, y))

    # 출력
    print(score)
    print(tile_count(green, "G") + tile_count(blue, "B"))
