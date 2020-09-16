def change_direction(d):
    if d == 1:
        return 2
    elif d == 2:
        return 1
    elif d == 3:
        return 4
    elif d == 4:
        return 3


def red_operation(key, pre_r, pre_c, post_r, post_c, chess, horse):
    if len(chess[pre_r][pre_c]) == 1:
        horse[key] = (post_r, post_c, horse[key][2])
        chess[post_r][post_c].append(chess[pre_r][pre_c][0])
        chess[pre_r][pre_c] = []
    else:
        index = chess[pre_r][pre_c].index(key)
        for i in range(len(chess[pre_r][pre_c]) - 1, index - 1, - 1):
            chess[post_r][post_c].append(chess[pre_r][pre_c][i])
            horse[chess[pre_r][pre_c][i]] = (post_r, post_c, horse[chess[pre_r][pre_c][i]][2])
        chess[pre_r][pre_c] = chess[pre_r][pre_c][:index]


def white_operation(key, pre_r, pre_c, post_r, post_c, chess, horse):
    if len(chess[pre_r][pre_c]) == 1:
        horse[key] = (post_r, post_c, horse[key][2])
        chess[post_r][post_c].append(chess[pre_r][pre_c][0])
        chess[pre_r][pre_c] = []
    else:
        index = chess[pre_r][pre_c].index(key)
        for i in range(index, len(chess[pre_r][pre_c])):
            chess[post_r][post_c].append(chess[pre_r][pre_c][i])
            horse[chess[pre_r][pre_c][i]] = (post_r, post_c, horse[chess[pre_r][pre_c][i]][2])
        chess[pre_r][pre_c] = chess[pre_r][pre_c][:index]


def blue_operation(key, chess, horse):
    r, c, d = horse[key]
    d = change_direction(d)
    horse[key] = (r, c, d)
    if d == 1:
        if c + 1 == n:
            return
        elif maps[r][c + 1] == 2:
            return
        else:  # 이동 가능
            if maps[r][c + 1] == 0:
                white_operation(key, r, c, r, c + 1, chess, horse)
            elif maps[r][c + 1] == 1:
                red_operation(key, r, c, r, c + 1, chess, horse)
    elif d == 2:
        if c - 1 < 0:
            return
        elif maps[r][c - 1] == 2:
            return
        else:
            if maps[r][c - 1] == 0:
                white_operation(key, r, c, r, c - 1, chess, horse)
            elif maps[r][c - 1] == 1:
                red_operation(key, r, c, r, c - 1, chess, horse)
    elif d == 3:
        if r - 1 < 0:
            return
        elif maps[r - 1][c] == 2:
            return
        else:
            if maps[r - 1][c] == 0:
                white_operation(key, r, c, r - 1, c, chess, horse)
            elif maps[r - 1][c] == 1:
                red_operation(key, r, c, r - 1, c, chess, horse)
    else:
        if r + 1 == n:
            return
        elif maps[r + 1][c] == 2:
            return
        else:
            if maps[r + 1][c] == 0:
                white_operation(key, r, c, r + 1, c, chess, horse)
            elif maps[r + 1][c] == 1:
                red_operation(key, r, c, r + 1, c, chess, horse)


def check(array):
    for i in range(n):
        for j in range(n):
            if len(array[i][j]) >= 4:
                return True
    return False


if __name__ == "__main__":
    n, k = map(int, input().split())  # 체스판의 크기, 말의 개수
    maps = [list(map(int, input().split())) for _ in range(n)]
    chess = [[[] for _ in range(n)] for _ in range(n)]
    horse = {}
    for i in range(1, k + 1):
        r, c, d = map(int, input().split())
        horse[i] = (r - 1, c - 1, d)
        chess[r - 1][c - 1].append(i)

    time = 0
    flag = True
    while time <= 1000 and flag:
        for key in horse.keys():  # 각 말들 이동 수행
            r, c, d = horse[key]

            if d == 1:  # 오른쪽
                if c + 1 < n:
                    if maps[r][c + 1] == 0:
                        white_operation(key, r, c, r, c + 1, chess, horse)
                    elif maps[r][c + 1] == 1:
                        red_operation(key, r, c, r, c + 1, chess, horse)
                    elif maps[r][c + 1] == 2:
                        blue_operation(key, chess, horse)
                else:
                    blue_operation(key, chess, horse)
                if (c + 1 < n and len(chess[r][c + 1]) >= 4) or (c - 1 >= 0 and len(chess[r][c - 1]) >= 4):
                    flag = False
                    break
            elif d == 2:  # 왼쪽
                if c - 1 >= 0:
                    if maps[r][c - 1] == 0:
                        white_operation(key, r, c, r, c - 1, chess, horse)
                    elif maps[r][c - 1] == 1:
                        red_operation(key, r, c, r, c - 1, chess, horse)
                    elif maps[r][c - 1] == 2:
                        blue_operation(key, chess, horse)
                else:
                    blue_operation(key, chess, horse)
                if (c + 1 < n and len(chess[r][c + 1]) >= 4) or (c - 1 >= 0 and len(chess[r][c - 1]) >= 4):
                    flag = False
                    break
            elif d == 3:  # 상
                if r - 1 >= 0:
                    if maps[r - 1][c] == 0:
                        white_operation(key, r, c, r - 1, c, chess, horse)
                    elif maps[r - 1][c] == 1:
                        red_operation(key, r, c, r - 1, c, chess, horse)
                    elif maps[r - 1][c] == 2:
                        blue_operation(key, chess, horse)
                else:
                    blue_operation(key, chess, horse)
                if (r + 1 < n and len(chess[r + 1][c]) >= 4) or (r - 1 >= 0 and len(chess[r - 1][c]) >= 4):
                    flag = False
                    break
            else:  # 하
                if r + 1 < n:
                    if maps[r + 1][c] == 0:
                        white_operation(key, r, c, r + 1, c, chess, horse)
                    elif maps[r + 1][c] == 1:
                        red_operation(key, r, c, r + 1, c, chess, horse)
                    elif maps[r + 1][c] == 2:
                        blue_operation(key, chess, horse)
                else:
                    blue_operation(key, chess, horse)
                if (r + 1 < n and len(chess[r + 1][c]) >= 4) or (r - 1 >= 0 and len(chess[r - 1][c]) >= 4):
                    flag = False
                    break
        time += 1

    # 출력
    if time > 1000:
        print(-1)
    else:
        print(time)
