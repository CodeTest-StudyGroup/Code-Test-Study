import sys
sys.setrecursionlimit(10 ** 9)

real_flag = True


def dfs(red, blue, visited, cnt):
    global answer

    # 현재 위치 visited 추가
    if (red[0], red[1], blue[0], blue[1]) in visited:
        if visited[(red[0], red[1], blue[0], blue[1])] < cnt:  # 더 빠른 방법으로 이미 지나간 상황
            return
        else:
            visited[(red[0], red[1], blue[0], blue[1])] = cnt
    else:
        visited[(red[0], red[1], blue[0], blue[1])] = cnt

    red_row = red[0]
    red_col = red[1]
    blue_row = blue[0]
    blue_col = blue[1]

    # 위쪽으로 기울기
    # 더 위에 있는 공이 먼저 기울어 지도록 구현
    red_find = False
    blue_find = False
    if red[0] <= blue[0]:
        for i in range(red[0] - 1, -1, -1):
            if array[i][red[1]] == "." and [i, red[1]] != [blue_row, blue_col]:
                red_row -= 1
            elif array[i][red[1]] == "O":
                red_row -= 1
                red_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = 'R'  # 구멍에 안들어가면 R이 남아있다.
        for i in range(blue[0] - 1, -1, -1):
            if array[i][blue[1]] == ".":
                blue_row -= 1
            elif array[i][blue[1]] == "O":
                blue_row -= 1
                blue_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = '.'  # 빈칸으로 다시 업데이트
    else:
        for i in range(blue[0] - 1, -1, -1):
            if array[i][blue[1]] == "." and [i, blue[1]] != [red_row, red_col]:
                blue_row -= 1
            elif array[i][blue[1]] == "O":
                blue_row -= 1
                blue_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = 'B'
        for i in range(red[0] - 1, -1, -1):
            if array[i][red[1]] == ".":
                red_row -= 1
            elif array[i][red[1]] == "O":
                red_row -= 1
                red_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = '.'
    if red_find and blue_find:  # 둘 다 찾은 상황:
        pass
    elif red_find:  # 레드만 구멍 찾은 상황
        answer = min(answer, cnt + 1)
    else:
        if (not red_find and not blue_find) and ([red[0], red[1]] != [red_row, red_col] or [blue[0], blue[1]] != [blue_row, blue_col]):
            if (red_row, red_col, blue_row, blue_col) not in visited:  # 위치 변동이 있던 경우
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)
            elif visited[(red_row, red_col, blue_row, blue_col)] > cnt + 1:
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)

    # 아래쪽으로 기울기
    red_row, red_col, blue_row, blue_col = red[0], red[1], blue[0], blue[1]
    red_find = False
    blue_find = False
    # 더 아래쪽에 있는게 먼저 기울어지도록
    if red_row >= blue_row:
        for i in range(red[0] + 1, n):
            if array[i][red[1]] == "." and [i, red[1]] != [blue_row, blue_col]:
                red_row += 1
            elif array[i][red[1]] == "O":
                red_row += 1
                red_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = 'R'  # 구멍에 안들어가면 R이 남아있다.
        for i in range(blue[0] + 1, n):
            if array[i][blue[1]] == ".":
                blue_row += 1
            elif array[i][blue[1]] == "O":
                blue_row += 1
                blue_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = '.'  # 빈칸으로 다시 업데이트
    else:
        for i in range(blue[0] + 1, n):
            if array[i][blue[1]] == "." and [i, blue[1]] != [red_row, red_col]:
                blue_row += 1
            elif array[i][blue[1]] == "O":
                blue_row += 1
                blue_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = 'B'
        for i in range(red[0] + 1, n):
            if array[i][red[1]] == ".":
                red_row += 1
            elif array[i][red[1]] == "O":
                red_row += 1
                red_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = '.'
    if red_find and blue_find:  # 둘 다 찾은 상황:
        pass
    elif red_find:  # 레드만 구멍 찾은 상황
        answer = min(answer, cnt + 1)
    else:
        if (not red_find and not blue_find) and ([red[0], red[1]] != [red_row, red_col] or [blue[0], blue[1]] != [blue_row, blue_col]):
            if (red_row, red_col, blue_row, blue_col) not in visited:  # 위치 변동이 있던 경우
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)
            elif visited[(red_row, red_col, blue_row, blue_col)] > cnt + 1:
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)

    # 왼쪽으로 기울기
    red_row, red_col, blue_row, blue_col = red[0], red[1], blue[0], blue[1]
    red_find = False
    blue_find = False
    # 더 왼쪽에 있는게 먼저 기울어지도록
    if red_col <= blue_col:
        for i in range(red[1] - 1, -1, -1):
            if array[red[0]][i] == "." and [red[0], i] != [blue_row, blue_col]:
                red_col -= 1
            elif array[red[0]][i] == "O":
                red_col -= 1
                red_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = 'R'  # 구멍에 안들어가면 R이 남아있다.
        for i in range(blue[1] - 1, -1, -1):
            if array[blue[0]][i] == ".":
                blue_col -= 1
            elif array[blue[0]][i] == "O":
                blue_col -= 1
                blue_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = '.'  # 빈칸으로 다시 업데이트
    else:
        for i in range(blue[1] - 1, -1, -1):
            if array[blue[0]][i] == "." and [blue[0], i] != [red_row, red_col]:
                blue_col -= 1
            elif array[blue[0]][i] == "O":
                blue_col -= 1
                blue_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = 'B'
        for i in range(red[1] - 1, -1, -1):
            if array[red[0]][i] == ".":
                red_col -= 1
            elif array[red[0]][i] == "O":
                red_col -= 1
                red_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = '.'
    if red_find and blue_find:  # 둘 다 찾은 상황:
        pass
    elif red_find:  # 레드만 구멍 찾은 상황
        answer = min(answer, cnt + 1)
    else:
        if (not red_find and not blue_find) and ([red[0], red[1]] != [red_row, red_col] or [blue[0], blue[1]] != [blue_row, blue_col]):
            if (red_row, red_col, blue_row, blue_col) not in visited:  # 위치 변동이 있던 경우
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)
            elif visited[(red_row, red_col, blue_row, blue_col)] > cnt + 1:
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)

    # 오른쪽으로 기울기
    red_row, red_col, blue_row, blue_col = red[0], red[1], blue[0], blue[1]
    red_find = False
    blue_find = False
    if red_col >= blue_col:
        for i in range(red[1] + 1, m):
            if array[red[0]][i] == "." and [red[0], i] != [blue_row, blue_col]:
                red_col += 1
            elif array[red[0]][i] == "O":
                red_col += 1
                red_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = 'R'  # 구멍에 안들어가면 R이 남아있다.
        for i in range(blue[1] + 1, m):
            if array[blue[0]][i] == ".":
                blue_col += 1
            elif array[blue[0]][i] == "O":
                blue_col += 1
                blue_find = True
                break
            else:
                break
        if not red_find:
            array[red_row][red_col] = '.'  # 빈칸으로 다시 업데이트
    else:
        for i in range(blue[1] + 1, m):
            if array[blue[0]][i] == "." and [blue[0], i] != [red_row, red_col]:
                blue_col += 1
            elif array[blue[0]][i] == "O":
                blue_col += 1
                blue_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = 'B'
        for i in range(red[1] + 1, m):
            if array[red[0]][i] == ".":
                red_col += 1
            elif array[red[0]][i] == "O":
                red_col += 1
                red_find = True
                break
            else:
                break
        if not blue_find:
            array[blue_row][blue_col] = '.'
    if red_find and blue_find:  # 둘 다 찾은 상황:
        pass
    elif red_find:  # 레드만 구멍 찾은 상황
        answer = min(answer, cnt + 1)
    else:
        if (not red_find and not blue_find) and ([red[0], red[1]] != [red_row, red_col] or [blue[0], blue[1]] != [blue_row, blue_col]):
            if (red_row, red_col, blue_row, blue_col) not in visited:  # 위치 변동이 있던 경우
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)
            elif visited[(red_row, red_col, blue_row, blue_col)] > cnt + 1:
                dfs([red_row, red_col], [blue_row, blue_col], visited, cnt + 1)


if __name__ == "__main__":
    n, m = map(int, input().split())  # 세로, 가로 크기 입력받음
    array = [list(input().strip()) for _ in range(n)]  # 지도 입력받음

    # 초기 레드, 블루 위치 찾기
    init_red, init_blue = [], []
    for i in range(n):
        for j in range(m):
            if array[i][j] == "R":
                init_red = [i, j]
                array[i][j] = '.'
            elif array[i][j] == "B":
                init_blue = [i, j]
                array[i][j] = '.'

    # 완전 탐색 구현
    visited = {}
    answer = 1e9  # 10억으로 초기화
    dfs(init_red, init_blue, visited, 0)

    if answer > 10:  # 10번 초과는 -1 출력
        print(-1)
    else:
        print(answer)