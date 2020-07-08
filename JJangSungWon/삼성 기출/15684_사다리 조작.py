import sys
from itertools import combinations


# 각 열을 움직였을때 결과 확인
def move():
    for i in range(1, N + 1):
        index = [0, i]  # 출발시 가로, 세로

        while index[0] < H:
            if connect[index[0] + 1][index[1]] == 1:  # 오른쪽 이동
                index[1] += 1
            elif index[1] - 1 >= 0 and connect[index[0] + 1][index[1] - 1] == 1:  # 왼쪽으로 이동
                index[1] -= 1
            index[0] += 1
        if index[1] != i:
            return 0
    return 1


# 인접 체크
def check(arr1, arr2):
    if arr1[0] == arr2[0]:
        if abs(arr1[1] - arr2[1]) == 1:
            return True
    return False


# 가로선 추가 상황 구현
def find():
    if M == 0 or move():   # 이미 구현된 상황
        return 0
    else:
        # 1개 추가로 가능한 상황
        for i in range(len(add)):
            row, col = add[i]
            connect[row][col] = 1
            if move():
                return 1
            else:
                connect[row][col] = 0

        # 2개 추가로 가능한 상황
        order = list(combinations(add, 2))
        for i in range(len(order)):
            if check(order[i][0], order[i][1]):  # 인접 확인
                continue
            connect[order[i][0][0]][order[i][0][1]] = 1
            connect[order[i][1][0]][order[i][1][1]] = 1
            if move():
                return 2
            else:
                connect[order[i][0][0]][order[i][0][1]] = 0
                connect[order[i][1][0]][order[i][1][1]] = 0

        # 3개 추가로 가능한 상황
        order = list(combinations(add, 3))
        for i in range(len(order)):
            if check(order[i][0], order[i][1]) or check(order[i][0], order[i][2]) or check(order[i][1], order[i][2]):
                continue
            connect[order[i][0][0]][order[i][0][1]] = 1
            connect[order[i][1][0]][order[i][1][1]] = 1
            connect[order[i][2][0]][order[i][2][1]] = 1
            if move():
                return 3
            else:
                connect[order[i][0][0]][order[i][0][1]] = 0
                connect[order[i][1][0]][order[i][1][1]] = 0
                connect[order[i][2][0]][order[i][2][1]] = 0

        # 나머지 상황
        return -1


if __name__ == "__main__":

    # input
    N, M, H = map(int, sys.stdin.readline().split())
    line = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]  # 가로선의 정보
    connect = [[0] * (N + 1) for _ in range(H + 1)]  # 전체 연결 정보

    # line 정보 -> connect 반영
    for i in range(len(line)):
        connect[line[i][0]][line[i][1]] = 1

    # 가로선 추가 가능한 영역 찾기
    add = []
    for i in range(1, H + 1):
        for j in range(1, N):
            if not (connect[i][j - 1] or connect[i][j] or connect[i][j + 1]):
                add.append([i, j])

    print(find())
