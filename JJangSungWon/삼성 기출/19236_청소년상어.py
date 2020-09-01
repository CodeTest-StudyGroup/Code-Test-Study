import copy

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, -1, -1, -1, 0, 1, 1, 1]


def food(array, x, y):  # 상어가 먹을 수 있는 후보 위치 반환
    positions = []
    direction = array[x][y][1]
    for i in range(1, 4):
        nx, ny = x + dx[direction], y + dy[direction]
        if 0 <= nx < 4 and 0 <= ny < 4 and 1 <= array[nx][ny][0] <= 16:
            positions.append([nx, ny])
        x, y = nx, ny
    return positions


# 현재 배열에서 특정한 번호의 물고기 위치 찾기
def find_fish(array, index):
    for i in range(4):
        for j in range(4):
            if array[i][j][0] == index:
                return (i, j)
    return None


def move_fish(array, now_x, now_y):  # 물고기 이동
    flag = False
    position = []
    for i in range(1, 17):
        position = find_fish(array, i)
        if position is None:
            continue
        x, y = position[0], position[1]
        dir = array[x][y][1]  # 방향
        for j in range(8):
            nx, ny = x + dx[dir], y + dy[dir]
            if 0 <= nx < 4 and 0 <= ny < 4:
                if not (nx == now_x and ny == now_y):  # 공간의 경계, 상어 있는 칸 확인
                    # 값 교체
                    array[x][y][0], array[nx][ny][0] = array[nx][ny][0], array[x][y][0]
                    array[x][y][1], array[nx][ny][1] = array[nx][ny][1], dir
                    break
            dir = (dir + 1) % 8


def dfs(array, x, y, total):
    global answer
    array = copy.deepcopy(array)

    # 해당 위치 물고기 먹기
    number = array[x][y][0]
    array[x][y][0] = -1

    # 물고기 이동
    move_fish(array, x, y)

    # 상어 이동할 수 있는 후보 확인
    result = food(array, x, y)

    # 해당 먹이 먹는 모든 과정 탐색
    answer = max(answer, total + number)
    for next_x, next_y in result:
        dfs(array, next_x, next_y, total + number)


if __name__ == "__main__":
    temp = [list(map(int, input().split())) for _ in range(4)]
    array = [[None] * 4 for _ in range(4)]
    # 배열을 다루기 쉽게 [값, 방향] 형태로 바꾼다.
    for i in range(4):
        for j in range(4):
            array[i][j] = [temp[i][j * 2], temp[i][j * 2 + 1] - 1]

    # dfs 탐색
    answer = 0
    dfs(array, 0, 0, 0)
    print(answer)
