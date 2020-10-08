import sys
def check(idx):
  if idx < len(zeros):
    ny = zeros[idx][0]
    nx = zeros[idx][1]
    for i in range(1, 10):
      if(horizontal(nx, i) and vertical(ny, i) and bythree(ny, nx, i)):
        sudoku[ny][nx] = i
        check(idx+1)
        sudoku[ny][nx] = 0
  else :
    printsudoku()
    sys.exit(0)

def horizontal(x, val):
  for i in range(9):
    if val == sudoku[i][x]:
      return False
  return True

def vertical(y, val):
  if val in sudoku[y]:
    return False
  return True

def bythree(y, x, val):
  nx = x // 3 * 3
  ny = y // 3 * 3
  for i in range(3):
    for j in range(3):
      if val == sudoku[ny + i][nx + j]:
        return False
  return True

def printsudoku():
  for i in range(9):
    for j in range(9):
      print(sudoku[i][j], end = " ")
    print()


sudoku = [list(map(int, input().strip().split())) for _ in range(9)]
zeros = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]
check(0)