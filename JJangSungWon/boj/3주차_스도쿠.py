# row check
def row_check(row, value):
    if value in data[row]:
        return False
    return True


# col check
def col_check(col, value):
    for i in range(9):
        if value == data[i][col]:
            return False
    return True


# 3 * 3 check
def three_check(row, col, value):
    for i in range(3):
        for j in range(3):
            if value == data[row//3 * 3 + i][col//3 * 3 + j]:
                return False
    return True


def dfs(cnt):
    if cnt == len(index):
        for i in range(9):
            print(" ".join(map(str, data[i])))
        exit()

    row, col = index[cnt]
    for k in range(1, 10):
        if row_check(row, k) and col_check(col, k) and three_check(row, col, k):
            data[row][col] = k
            dfs(cnt + 1)
            data[row][col] = 0


if __name__ == "__main__":
    data = []
    # input
    for _ in range(9):
        data.append(list(map(int, input().split())))

    # find blank
    index = []
    for i in range(9):
        for j in range(9):
            if data[i][j] == 0:
                index.append((i, j))
    dfs(0)
