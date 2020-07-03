import sys
import copy


def dfs(idx):
    global min_area, arr
    if idx == len(position):
        temp = 0
        for i in range(N):
            for j in range(M):
                if arr[i][j] == 0:
                    temp += 1
        min_area = min(min_area, temp)
    else:
        value, row, col = position[idx]
        temp = copy.deepcopy(arr)
        if value == 1:
            # ╩С
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)

            # го
            arr = copy.deepcopy(temp)
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)

            # аб
            arr = copy.deepcopy(temp)
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)

            # ©Л
            arr = copy.deepcopy(temp)
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)
        elif value == 2:
            # ╩С, го
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)

            # аб, ©Л
            arr = copy.deepcopy(temp)
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)
        elif value == 3:
            # ╩С, ©Л
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)

            # ©Л, го
            arr = copy.deepcopy(temp)
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)

            # го, аб
            arr = copy.deepcopy(temp)
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)

            # аб, ╩С
            arr = copy.deepcopy(temp)
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)
        elif value == 4:
            # аб, ╩С, ©Л
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)

            # ╩С, ©Л, го
            arr = copy.deepcopy(temp)
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)

            # ©Л, го, аб
            arr = copy.deepcopy(temp)
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)

            # го, аб, ╩С
            arr = copy.deepcopy(temp)
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            dfs(idx + 1)
        else:
            # ╩С
            for i in range(row - 1, -1, -1):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            # го
            for i in range(row + 1, N):
                if arr[i][col] == 0:
                    arr[i][col] = '#'
                elif arr[i][col] == 6:
                    break
            # аб
            for i in range(col -1, -1, -1):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            # ©Л
            for i in range(col + 1, M):
                if arr[row][i] == 0:
                    arr[row][i] = '#'
                elif arr[row][i] == 6:
                    break
            dfs(idx + 1)


if __name__ == "__main__":

    # input
    N, M = map(int, sys.stdin.readline().split())  # ╪╪╥н, ╟║╥н
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    # CCTY ю╖д║ ╟║а╝©ю╠Б
    position = []
    for i in range(N):
        for j in range(M):
            if arr[i][j] != 0 and arr[i][j] != 6:
                position.append(([arr[i][j], i, j]))

    min_area = sys.maxsize
    dfs(0)
    print(min_area)