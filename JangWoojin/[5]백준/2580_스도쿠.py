import sys
input = sys.stdin.readline


def dfs(idx, rows, cols, sqrs, blanks, sudoku):
    if idx == len(blanks):
        return True
    row, col = blanks[idx]
    flag = False
    for i in range(1, 10):
        if not rows[row][i] and not cols[col][i] and not sqrs[row // 3 * 3 + col // 3][i]:
            sudoku[row][col] = i
            rows[row][i] = True
            cols[col][i] = True
            sqrs[row // 3 * 3 + col // 3][i] = True
            if dfs(idx+1, rows, cols, sqrs, blanks, sudoku):
                return True
            sudoku[row][col] = 0
            rows[row][i] = False
            cols[col][i] = False
            sqrs[row // 3 * 3 + col // 3][i] = False
    return flag


def solve():
    sudoku = []
    rows = [[False] * 10 for _ in range(9)]
    cols = [[False] * 10 for _ in range(9)]
    sqrs = [[False] * 10 for _ in range(9)]
    blanks = []
    for _ in range(9):
        sudoku.append(list(map(int, input().split())))
    for i in range(9):
        for j in range(9):
            num = sudoku[i][j]
            if num == 0:
                blanks.append((i, j))
            else:
                rows[i][num] = True
                cols[j][num] = True
                sqrs[i // 3 * 3 + j // 3][num] = True
    dfs(0, rows, cols, sqrs, blanks, sudoku)
    for i in range(9):
        for j in range(9):
            print(sudoku[i][j], end=' ')
        print()


if __name__ == '__main__':
    solve()
