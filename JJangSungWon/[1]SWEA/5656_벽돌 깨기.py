import copy
from collections import deque


def wall_count(array):  # 벽돌 개수
    cnt = 0
    for i in range(h):
        for j in range(w):
            if array[i][j] != 0:
                cnt += 1
    return cnt


def remove_blank(array):
    flag = False
    for i in range(h - 2, -1, -1):
        for j in range(w):
            if array[i][j] == 0:
                continue
            if array[i + 1][j] == 0:
                flag = True
                array[i + 1][j] = array[i][j]
                array[i][j] = 0
    return flag


def dfs(idx, col, array):
    global answer
    if idx > n:
        answer = min(answer, wall_count(array))
        return

    if answer == 0:
        return
    elif wall_count(array) == 0:
        answer = 0
        return

    # col 열 벽 부수기
    q = deque()
    for i in range(h):
        if array[i][col] != 0:
            q.append((i, col, array[i][col]))
            array[i][col] = 0
            break

    if len(q) == 0:
        return

    while q:
        x, y, power = q.popleft()

        # 위
        for i in range(x - 1, x - power, -1):
            if i == -1:
                break
            if array[i][y] != 0:
                q.append((i, y, array[i][y]))
                array[i][y] = 0

        # 아래
        for i in range(x + 1, x + power):
            if i >= h:
                break
            if array[i][y] != 0:
                q.append((i, y, array[i][y]))
                array[i][y] = 0

        # 왼쪽
        for i in range(y - 1, y - power, -1):
            if i == -1:
                break
            if array[x][i] != 0:
                q.append((x, i, array[x][i]))
                array[x][i] = 0

        # 오른쪽
        for i in range(y + 1, y + power):
            if i >= w:
                break
            if array[x][i] != 0:
                q.append((x, i, array[x][i]))
                array[x][i] = 0

    # 빈공간 제거
    while True:
        if not remove_blank(array):
            break

    for i in range(w):
        copy_arr = copy.deepcopy(array)
        dfs(idx + 1, i, copy_arr)


if __name__ == "__main__":
    for tc in range(1, int(input()) + 1):
        n, w, h = map(int, input().split())
        array = [list(map(int, input().split())) for _ in range(h)]

        answer = 1e9
        # dfs 완전 탐색
        for i in range(w):
            copy_array = copy.deepcopy(array)
            dfs(1, i, copy_array)

        print("#{} {}".format(tc, answer))
