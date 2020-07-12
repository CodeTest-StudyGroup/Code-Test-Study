# 공기청정기 위치 파악
def air_position():
    for i in range(R):
        if arr[i][0] == -1:
            return [i, 0], [i + 1, 0]  # 위, 아래 공기청정기 위치


# 미세먼지 이동
def dust_move():
    temp = [[0] * C for _ in range(R)]  # 확산값 저장
    for i in range(R):
        for j in range(C):
            if arr[i][j] >= 5:
                val = 0  # 얼마나 확산했는지
                # 상
                if i - 1 >= 0 and arr[i - 1][j] != -1:
                    temp[i - 1][j] += arr[i][j] // 5
                    val += arr[i][j] // 5
                # 하
                if i + 1 < R and arr[i + 1][j] != -1:
                    temp[i + 1][j] += arr[i][j] // 5
                    val += arr[i][j] // 5
                # 좌
                if j - 1 >= 0 and arr[i][j - 1] != -1:
                    temp[i][j - 1] += arr[i][j] // 5
                    val += arr[i][j] // 5
                # 우
                if j + 1 < C and arr[i][j + 1] != -1:
                    temp[i][j + 1] += arr[i][j] // 5
                    val += arr[i][j] // 5
                temp[i][j] -= val  # 확산값 빼기
    for i in range(R):
        for j in range(C):
            arr[i][j] += temp[i][j]  # 확산받은 값 더하기


def air_move():
    # up
    # 1 - 아래
    temp = arr[up[0]][C - 1]
    for i in range(C - 1, 1, - 1):
        arr[up[0]][i] = arr[up[0]][i - 1]
    arr[up[0]][1] = 0

    # 2 - 오른쪽
    temp_1 = arr[0][C - 1]
    for i in range(up[0] - 1):
        arr[i][C - 1] = arr[i + 1][C - 1]
    arr[up[0] - 1][C - 1] = temp

    # 3 - 위쪽
    temp_2 = arr[0][0]
    for i in range(C - 2):
        arr[0][i] = arr[0][i + 1]
    arr[0][C - 2] = temp_1

    # 4 - 왼쪽
    for i in range(up[0] - 1, 1, -1):
        arr[i][0] = arr[i - 1][0]
    arr[1][0] = temp_2

    # down
    # 1- 위쪽
    temp = arr[down[0]][C - 1]
    for i in range(C - 1, 1, -1):
        arr[down[0]][i] = arr[down[0]][i - 1]
    arr[down[0]][1] = 0

    # 2 오른쪽
    temp_1 = arr[R - 1][C - 1]
    for i in range(R - 1, down[0] + 1, -1):
        arr[i][C - 1] = arr[i - 1][C - 1]
    arr[down[0] + 1][C - 1] = temp

    # 3 - 아래쪽
    temp_2 = arr[R - 1][0]
    for i in range(C - 2):
        arr[R - 1][i] = arr[R - 1][i + 1]
    arr[R - 1][C - 2] = temp_1

    # 4 - 왼쪽
    for i in range(down[0] + 1, R - 1):
        arr[i][0] = arr[i + 1][0]
    arr[R - 2][0] = temp_2


if __name__ == "__main__":

    # input
    R, C, T = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(R)]

    # 공기청정기 위치 가져오기
    up, down = air_position()

    # T시간 동안 시뮬레이션
    for i in range(T):
        dust_move()  # 미세먼지 이동
        air_move()  # 공기청정기 작동


    total = 0
    for i in range(R):
        for j in range(C):
            if arr[i][j] > 0:
                total += arr[i][j]
    print(total)