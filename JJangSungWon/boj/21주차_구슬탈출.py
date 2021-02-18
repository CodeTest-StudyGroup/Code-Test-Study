from collections import deque
import sys


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(red_x, red_y, blue_x, blue_y):
    q = deque()
    q.append((red_x, red_y, blue_x, blue_y, 0))
    visited = set()
    visited.add((red_x, red_y, blue_x, blue_y))

    while q:
        red_x, red_y, blue_x, blue_y, cnt = q.popleft()
        for i in range(4):
            red_flag, blue_flag = False, False
            red_cnt, blue_cnt = 0, 0
            new_red_x, new_red_y, new_blue_x, new_blue_y = red_x, red_y, blue_x, blue_y
            # red
            while maps[new_red_x + dx[i]][new_red_y + dy[i]] != '#':
                if maps[new_red_x + dx[i]][new_red_y + dy[i]] == 'O':
                    red_flag = True
                    break
                else:
                    new_red_x, new_red_y = dx[i] + new_red_x, dy[i] + new_red_y
                red_cnt += 1

            # blue
            while maps[new_blue_x + dx[i]][new_blue_y + dy[i]] != '#':
                if maps[new_blue_x + dx[i]][new_blue_y + dy[i]] == 'O':
                    blue_flag = True
                    break
                else:
                    new_blue_x, new_blue_y = dx[i] + new_blue_x, dy[i] + new_blue_y
                blue_cnt += 1

            if red_flag and blue_flag:
                continue
            elif red_flag:  # 빨간 구슬을 10번 이하로 움직여서 빼낼 수 있는 상황
                return 1
            elif cnt <= 8 and not blue_flag:
                if new_red_x == new_blue_x and new_red_y == new_blue_y:  # 위치가 겹치는 상황황
                   if red_cnt > blue_cnt:
                       new_red_x, new_red_y = new_red_x - dx[i], new_red_y - dy[i]
                   else:
                        new_blue_x, new_blue_y = new_blue_x - dx[i], new_blue_y - dy[i]
                if (new_red_x, new_red_y, new_blue_x, new_blue_y) not in visited:
                    q.append((new_red_x, new_red_y, new_blue_x, new_blue_y, cnt + 1))
                    visited.add((new_red_x, new_red_y, new_blue_x, new_blue_y))
    return 0


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [list(map(str, sys.stdin.readline().strip())) for _ in range(n)]

    # 빨간 구슬, 파란 구슬 위치 찾기
    red_location = [None, None]
    blue_location = [None, None]
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if maps[i][j] == 'R':
                red_location = [i, j]
            if maps[i][j] == 'B':
                blue_location = [i, j]
            if red_location[0] is not None and blue_location[0] is not None:  # 모두 찾은 경우
                break

    print(bfs(red_location[0], red_location[1], blue_location[0], blue_location[1]))
