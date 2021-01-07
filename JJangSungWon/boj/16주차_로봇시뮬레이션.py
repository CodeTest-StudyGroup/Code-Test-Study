import sys


def rotation_left(d):  # 왼쪽으로 90도 회전
    if d == "N":
        return "W"
    elif d == "W":
        return "S"
    elif d == "S":
        return "E"
    elif d == "E":
        return "N"


def rotation_right(d):  # 오른쪽으로 90도 회전
    if d == "N":
        return "E"
    elif d == "E":
        return "S"
    elif d == "S":
        return "W"
    elif d == "W":
        return "N"


def check(x, y):
    if d == "N":
        if x - 1 < 0:
            return 'wall'
        elif maps[x - 1][y]:
            return 'robot'
        else:
            return True
    elif d == "W":
        if y - 1 < 0:
            return 'wall'
        elif maps[x][y - 1]:
            return 'robot'
        else:
            return True
    elif d == "S":
        if x + 1 >= B:
            return 'wall'
        elif maps[x + 1][y]:
            return 'robot'
        else:
            return True
    elif d == "E":
        if y + 1 >= A:
            return 'wall'
        elif maps[x][y + 1]:
            return 'robot'
        else:
            return True


def move(x, y, d):
    if d == "N":
        return x - 1, y, d
    elif d == "W":
        return x, y - 1, d
    elif d == "S":
        return x + 1, y, d
    elif d == "E":
        return x, y + 1, d


if __name__ == "__main__":
    A, B = map(int, sys.stdin.readline().split())
    N, M = map(int, sys.stdin.readline().split())
    maps = [[None] * A for _ in range(B)]
    robot = dict()
    for i in range(N):  # 로봇의 초기 위치 및 방향 입력
        x, y, d = sys.stdin.readline().split()
        x, y = int(x), int(y)
        maps[B - y][x - 1] = [d, i + 1]
        robot[i + 1] = [B - y, x - 1, d]

    flag = True
    for i in range(M):  # 명령 수행
        if flag:
            number, order, cnt = sys.stdin.readline().split()
            number, cnt = int(number), int(cnt)
            for _ in range(cnt):
                if flag:
                    x, y, d = robot[number]
                    if order == "L":
                        d = rotation_left(d)
                        robot[number] = [x, y, d]
                    elif order == "R":
                        d = rotation_right(d)
                        robot[number] = [x, y, d]
                    elif order == "F":
                        temp = check(x, y)
                        if temp == 'wall':
                            print("Robot {} crashes into the wall".format(number))
                            flag = False
                            break
                        elif temp == 'robot':
                            x, y, d = move(x, y, d)
                            print("Robot {} crashes into robot {}".format(number, maps[x][y][1]))
                            flag = False
                            break
                        else:
                            maps[x][y] = None
                            x, y, d = move(x, y, d)
                            robot[number] = x, y, d
                            maps[x][y] = [d, number]

    # 출력
    if flag:
        print("OK")
