def calcul(row, col, case):
    global max_area

    for i in range(len(case)):
        area, flag = 0, 1
        for j in range(4):
            new_row, new_col = case[i][j]
            new_row += row
            new_col += col

            if 0 <= new_row < N and 0 <= new_col < M:
                area += data[new_row][new_col]
            else:
                flag = 0
                break
        if flag == 1:
            max_area = max(max_area, area)


def dfs(row, col):
    global max_area

    case1 = [[(0, 0), (0, 1), (0, 2), (0, 3)], [(0, 0), (1, 0), (2, 0), (3, 0)]]
    case2 = [[(0, 0), (0, 1), (1, 0), (1, 1)]]
    case3 = [[(0, 0), (1, 0), (2, 0), (2, 1)], [(0, 0), (0, 1), (-1, 1), (-2, 1)], [(0, 0), (1, 0), (0, 1), (0, 2)],
             [(0, 0), (0, 1), (0, 2), (1, 2)], [(0, 0), (0, 1), (1, 1), (2, 1)], [(0, 0), (1, 0), (2, 0), (0, 1)],
             [(0, 0), (0, 1), (0, 2), (-1, 2)], [(0, 0), (1, 0), (1, 1), (1, 2)]]
    case4 = [[(0, 0), (1, 0), (1, 1), (2, 1)], [(0, 0), (-1, 0), (-1, 1), (-2, 1)], [(0, 0), (0, 1), (-1, 1), (-1, 2)],
             [(0, 0), (0, 1), (1, 1), (1, 2)]]
    case5 = [[(0, 0), (0, 1), (0, 2), (1, 1)], [(0, 0), (0, 1), (-1, 1), (0, 2)], [(0, 0), (1, 0), (2, 0), (1, 1)],
             [(0, 0), (0, 1), (-1, 1), (1, 1)]]

    # case1
    calcul(row, col, case1)

    # case2
    calcul(row, col, case2)

    # case3
    calcul(row, col, case3)

    # case4
    calcul(row, col, case4)

    # case5
    calcul(row, col, case5)


if __name__ == "__main__":

    # input
    N, M = map(int, input().split())
    data = [list(map(int, input().split())) for _ in range(N)]

    max_area = - 1
    for i in range(N):
        for j in range(M):
            dfs(i, j)

    print(max_area)
