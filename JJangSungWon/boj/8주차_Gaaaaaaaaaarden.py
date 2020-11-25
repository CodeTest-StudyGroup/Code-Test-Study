from itertools import combinations
from collections import deque
import sys
import copy

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(array, selected, green):
    cnt = 0
    green_q = deque()
    red_q = deque()

    for row, col in selected:
        if [row, col] in green:
            green_q.append([row, col])  # 초록색 배양액
            array[row][col] = 3
        else:
            red_q.append([row, col])  # 빨간색 배양액
            array[row][col] = 4

    while green_q:  # 초록색 배양액이 빌때까지
        green_temp = set()
        red_temp = set()
        while green_q:
            x, y = green_q.popleft()
            array[x][y] = 3
            for i in range(4):
                new_x, new_y = x + dx[i], y + dy[i]
                if 0 <= new_x < n and 0 <= new_y < m:
                    if array[new_x][new_y] == 1 or array[new_x][new_y] == 2:
                        green_temp.add((new_x, new_y))
        while red_q:
            x, y = red_q.popleft()
            array[x][y] = 4
            for i in range(4):
                new_x, new_y = x + dx[i], y + dy[i]
                if 0 <= new_x < n and 0 <= new_y < m:
                    if array[new_x][new_y] == 1 or array[new_x][new_y] == 2:
                        red_temp.add((new_x, new_y))

        inter = green_temp & red_temp
        green_temp = green_temp - inter
        red_temp = red_temp - inter
        for row, col in inter:
            array[row][col] = 5
            cnt += 1
        for row, col in green_temp:
            array[row][col] = 3
        for row, col in red_temp:
            array[row][col] = 4
        green_q.extend(green_temp)
        red_q.extend(red_temp)

    return cnt


if __name__ == "__main__":
    n, m, g, r = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    # 배양액을 뿌릴 수 있는 위치, 뿌릴 수 없는 위치 탐색
    location = []
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 2:
                location.append([i, j])

    answer = 0
    for selected in list(combinations(location, g + r)):
        # selected를 green과 red로 나누기
        for green in list(combinations(selected, g)):
            copy_maps = copy.deepcopy(maps)
            answer = max(answer, bfs(copy_maps, selected, green))

    # 출력
    print(answer)
