"""
처음에 완탐 BFS로 구현하였지만 시간 초과가 발생하였다.
key와 lock의 크기를 고려하여 큰 배열을 만든 후 중앙에 lock을 두고 key를 움직이는 방식으로 구현하였다.
"""

import copy


def rotation(key):  # 90도 회전
    result = copy.deepcopy(key)

    for i in range(len(key)):
        temp = [0] * len(key)
        for j in range(len(key) - 1, -1, -1):
            temp[j] = result[j][i]
        temp.reverse()
        key[i] = copy.deepcopy(temp)

"""
def move(direction, key):
    if direction == 1:  # 상
        for i in range(1, len(key)):
            for j in range(len(key)):
                key[i - 1][j] = key[i][j]
        key[len(key) - 1] = [0] * len(key)
    elif direction == 2:  # 하
        for i in range(len(key) - 1, 0, -1):
            for j in range(len(key)):
                key[i][j] = key[i - 1][j]
        key[0] = [0] * len(key)
    elif direction == 3:  # 좌
        for i in range(len(key)):
            for j in range(len(key) - 1):
                key[i][j] = key[i][j + 1]
            key[i][len(key) - 1] = 0
    else:  # 우
        for i in range(len(key)):
            for j in range(len(key) - 1, 0, -1):
                key[i][j] = key[i][j - 1]
            key[i][0] = 0


def check(key, position):
    key_position = []
    for i in range(len(key)):
        for j in range(len(key)):
            if key[i][j] == 1:
                key_position.append([i, j])

    for i in range(len(position)):
        if position[i] not in key_position:
            return 0
    return 1
"""

def unlock(row, col, key, lock):
    key_len = len(key)
    lock_len = len(lock)
    size = key_len * 2 + lock_len - 2

    arr = [[0] * size for _ in range(size)]

    # 배열에 key 값 대입
    for i in range(key_len):
        for j in range(key_len):
            arr[row + i][col + j] += key[i][j]

    # 대입 된 key값과 중앙에 있는 lock값의 연산을 통해 결과 도출
    for i in range(key_len - 1, key_len + lock_len - 1):
        for j in range(key_len - 1, key_len + lock_len - 1):
            arr[i][j] += lock[i - (key_len - 1)][j - (key_len - 1)]

            # 모든 값이 1이면 key와 lock이 True인 상황
            if arr[i][j] != 1:
                return False
    return True


def solution(key, lock):
    key_len, lock_len = len(key), len(lock)

    for d in range(4):  # 0 90 270 회전
        for i in range(key_len + lock_len - 1):
            for j in range(key_len + lock_len - 1):
                if unlock(i, j, key, lock):
                    return True
        rotation(key)
    return False


if __name__ == "__main__":
    print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
