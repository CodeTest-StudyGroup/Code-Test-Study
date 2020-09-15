dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]


def get_shark(idx, maps):
    for row in range(1, R + 1):
        if maps[row][idx] != 0:
            s, d, z = maps[row][idx]
            maps[row][idx] = 0
            return z
    return 0


def move_shakr(maps):
    new_shark = [[0 for _ in range(C + 1)] for _ in range(R + 1)]
    for x in range(1, len(maps)):
        for y in range(1, len(maps[0])):
            if maps[x][y] != 0:
                speed, dir, size = maps[x][y]

                if dir == 0 or dir == 1:
                    speed %= (2 * (len(maps) - 1) - 2)
                else:
                    speed %= (2 * (len(maps[0]) - 1) - 2)

                # 시작할 때 방향을 전환해야하는 경우
                nx, ny = x, y
                if nx == 1 and dir == 0:
                    dir = 1
                elif nx == len(maps) - 1 and dir == 1:
                    dir = 0
                elif ny == 1 and dir == 3:
                    dir = 2
                elif ny == len(maps[0]) - 1 and dir == 2:
                    dir = 3
                for _ in range(speed):
                    if dir == 0:
                        nx -= 1
                        if nx == 1:
                            dir = 1
                    elif dir == 1:
                        nx += 1
                        if nx == len(maps) - 1:
                            dir = 0
                    elif dir == 2:
                        ny += 1
                        if ny == len(maps[0]) - 1:
                            dir = 3
                    else:
                        ny -= 1
                        if ny == 1:
                            dir = 2

                if new_shark[nx][ny] == 0 or size > new_shark[nx][ny][2]:
                    new_shark[nx][ny] = (speed, dir, size)
    return new_shark


if __name__ == "__main__":
    R, C, M = map(int, input().split())  # 격자판의크기, 상어의 수
    maps = [[0 for _ in range(C + 1)] for _ in range(R + 1)]  # 지도
    for _ in range(M):
        r, c, s, d, z = map(int, input().split())
        maps[r][c] = (s, d - 1, z)

    answer = 0
    for idx in range(1, C + 1):
        answer += get_shark(idx, maps)  # 상어 낚시
        maps = move_shakr(maps)  # 상어 이동

    print(answer)
