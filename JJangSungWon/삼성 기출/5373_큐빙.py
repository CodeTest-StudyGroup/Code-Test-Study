import copy


def arr_rotation(arr, flag):  # 2차원 배열 90도 회전
    rotation = [[0] * 3 for _ in range(3)]
    if flag == "+":  # 시계 방향
        for i in range(3):
            for j in range(3):
                rotation[i][j] = arr[3 - j - 1][i]
    else:  # 반시계
        for i in range(3):
            for j in range(3):
                rotation[i][j] = arr[j][3 - i - 1]
    arr = copy.deepcopy(rotation)
    return arr


def rotation(side, dir):
    global top, bottom, front, back, left, right

    if side == "U":
        top = arr_rotation(top, dir)
        if dir == "+":  # 윗면이 시계방향으로 회전
            temp = [right[0][0], right[0][1], right[0][2]]
            right[0][0], right[0][1], right[0][2] = back[0][0], back[0][1], back[0][2]
            back[0][0], back[0][1], back[0][2] = left[0][0], left[0][1], left[0][2]
            left[0][0], left[0][1], left[0][2] = front[0][0], front[0][1], front[0][2]
            front[0][0], front[0][1], front[0][2] = temp[0], temp[1], temp[2]
        else:
            temp = [right[0][0], right[0][1], right[0][2]]
            right[0][0], right[0][1], right[0][2] = front[0][0], front[0][1], front[0][2]
            front[0][0], front[0][1], front[0][2] = left[0][0], left[0][1], left[0][2]
            left[0][0], left[0][1], left[0][2] = back[0][0], back[0][1], back[0][2]
            back[0][0], back[0][1], back[0][2] = temp[0], temp[1], temp[2]
    elif side == "D":
        bottom = arr_rotation(bottom, dir)
        if dir == "+":
            temp = [right[2][0], right[2][1], right[2][2]]
            right[2][0], right[2][1], right[2][2] = front[2][0], front[2][1], front[2][2]
            front[2][0], front[2][1], front[2][2] = left[2][0], left[2][1], left[2][2]
            left[2][0], left[2][1], left[2][2] = back[2][0], back[2][1], back[2][2]
            back[2][0], back[2][1], back[2][2] = temp[0], temp[1], temp[2]
        else:
            temp = [right[2][0], right[2][1], right[2][2]]
            right[2][0], right[2][1], right[2][2] = back[2][0], back[2][1], back[2][2]
            back[2][0], back[2][1], back[2][2] = left[2][0], left[2][1], left[2][2]
            left[2][0], left[2][1], left[2][2] = front[2][0], front[2][1], front[2][2]
            front[2][0], front[2][1], front[2][2] = temp[0], temp[1], temp[2]
    elif side == "F":
        front = arr_rotation(front, dir)
        if dir == "+":
            temp = [top[2][0], top[2][1], top[2][2]]
            top[2][0], top[2][1], top[2][2] = left[2][2], left[1][2], left[0][2]
            left[2][2], left[1][2], left[0][2] = bottom[0][2], bottom[0][1], bottom[0][0]
            bottom[0][2], bottom[0][1], bottom[0][0] = right[0][0], right[1][0], right[2][0]
            right[0][0], right[1][0], right[2][0] = temp[0], temp[1], temp[2]
        else:
            temp = [top[2][0], top[2][1], top[2][2]]
            top[2][0], top[2][1], top[2][2] = right[0][0], right[1][0], right[2][0]
            right[0][0], right[1][0], right[2][0] = bottom[0][2], bottom[0][1], bottom[0][0]
            bottom[0][2], bottom[0][1], bottom[0][0] = left[2][2], left[1][2], left[0][2]
            left[2][2], left[1][2], left[0][2] = temp[0], temp[1], temp[2]
    elif side == "B":
        back = arr_rotation(back, dir)
        if dir == "+":
            temp = [top[0][0], top[0][1], top[0][2]]
            top[0][0], top[0][1], top[0][2] = right[0][2], right[1][2], right[2][2]
            right[0][2], right[1][2], right[2][2] = bottom[2][2], bottom[2][1], bottom[2][0]
            bottom[2][2], bottom[2][1], bottom[2][0] = left[2][0], left[1][0], left[0][0]
            left[2][0], left[1][0], left[0][0] = temp[0], temp[1], temp[2]
        else:
            temp = [top[0][0], top[0][1], top[0][2]]
            top[0][0], top[0][1], top[0][2] = left[2][0], left[1][0], left[0][0]
            left[2][0], left[1][0], left[0][0] = bottom[2][2], bottom[2][1], bottom[2][0]
            bottom[2][2], bottom[2][1], bottom[2][0] = right[0][2], right[1][2], right[2][2]
            right[0][2], right[1][2], right[2][2] = temp[0], temp[1], temp[2]
    elif side == "L":
        left = arr_rotation(left, dir)
        if dir == "+":
            temp = [top[0][0], top[1][0], top[2][0]]
            top[0][0], top[1][0], top[2][0] = back[2][2], back[1][2], back[0][2]
            back[2][2], back[1][2], back[0][2] = bottom[0][0], bottom[1][0], bottom[2][0]
            bottom[0][0], bottom[1][0], bottom[2][0] = front[0][0], front[1][0], front[2][0]
            front[0][0], front[1][0], front[2][0] = temp[0], temp[1], temp[2]
        else:
            temp = [top[0][0], top[1][0], top[2][0]]
            top[0][0], top[1][0], top[2][0] = front[0][0], front[1][0], front[2][0]
            front[0][0], front[1][0], front[2][0] = bottom[0][0], bottom[1][0], bottom[2][0]
            bottom[0][0], bottom[1][0], bottom[2][0] = back[2][2], back[1][2], back[0][2]
            back[2][2], back[1][2], back[0][2] = temp[0], temp[1], temp[2]
    elif side == "R":
        right = arr_rotation(right, dir)
        if dir == "+":
            temp = [top[2][2], top[1][2], top[0][2]]
            top[2][2], top[1][2], top[0][2] = front[2][2], front[1][2], front[0][2]
            front[2][2], front[1][2], front[0][2] = bottom[2][2], bottom[1][2], bottom[0][2]
            bottom[2][2], bottom[1][2], bottom[0][2] = back[0][0], back[1][0], back[2][0]
            back[0][0], back[1][0], back[2][0] = temp[0], temp[1], temp[2]
        else:
            temp = [top[2][2], top[1][2], top[0][2]]
            top[2][2], top[1][2], top[0][2] = back[0][0], back[1][0], back[2][0]
            back[0][0], back[1][0], back[2][0] = bottom[2][2], bottom[1][2], bottom[0][2]
            bottom[2][2], bottom[1][2], bottom[0][2] = front[2][2], front[1][2], front[0][2]
            front[2][2], front[1][2], front[0][2] = temp[0], temp[1], temp[2]


if __name__ == "__main__":
    for _ in range(int(input())):  # 테스트 케이스만큼 반복
        n = int(input())  # 큐브를 돌린 횟수
        data = list(map(str, input().split(" ")))  # 공백을 기준으로 분리

        top = [['w'] * 3 for _ in range(3)]  # 위
        bottom = [['y'] * 3 for _ in range(3)]  # 아래
        front = [['r'] * 3 for _ in range(3)]  # 앞
        back = [['o'] * 3 for _ in range(3)]  # 뒤
        left = [['g'] * 3 for _ in range(3)]  # 왼쪽
        right = [['b'] * 3 for _ in range(3)]  # 오른쪽

        for i in range(n):  # 회전
            rotation(data[i][0], data[i][1])  # 면, 방향

        for i in range(3):
            print("".join(map(str, top[i])))
