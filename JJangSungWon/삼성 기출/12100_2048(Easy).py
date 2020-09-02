import copy


def dfs(cnt, board):
    global answer
    if cnt > 5:  # 5번까지만 이동 가능하다.
        for i in range(n):
            for j in range(n):
                if board[i][j] is not None:
                    answer = max(answer, board[i][j][0])
        return

    copy_board = copy.deepcopy(board)  # 복사본 저장

    # 위로 이동
    for k in range(n):
        for i in range(1, n):  # 위에 있는 것부터 움직인다.
            if board[i][k] is None:  # 빈칸은 움직일 필가 없다.
                continue
            row = i
            for j in range(i - 1, -1, -1):
                if board[j][k] is None:  # 이동할 칸이 빈칸이면
                    board[j][k] = board[row][k]
                    board[row][k] = None  # 현재 칸 빈칸으로 업데이트
                elif board[j][k][0] == board[row][k][0] and not board[j][k][1]:  # 값이 같고 아직 합쳐지지 않았다면
                    board[j][k][0] *= 2
                    board[j][k][1] = True
                    board[row][k] = None
                    break
                else:
                    break
                row -= 1
    for i in range(n):
        for j in range(n):
            if board[i][j] is not None:
                board[i][j][1] = False
    dfs(cnt + 1, board)
    board = copy.deepcopy(copy_board)

    # 아래로 이동
    for k in range(n):
        for i in range(n - 2, -1, -1):  # 아래에 있는 것부터 움직인다.
            if board[i][k] is None:  # 빈칸은 움직일 필가 없다.
                continue
            row = i
            for j in range(i + 1, n):
                if board[j][k] is None:  # 이동할 칸이 빈칸이면
                    board[j][k] = board[row][k]
                    board[row][k] = None  # 현재 칸 빈칸으로 업데이트
                elif board[j][k][0] == board[row][k][0] and not board[j][k][1]:  # 값이 같고 아직 합쳐지지 않았다면
                    board[j][k][0] *= 2
                    board[j][k][1] = True
                    board[row][k] = None
                    break
                else:
                    break
                row += 1
    for i in range(n):
        for j in range(n):
            if board[i][j] is not None:
                board[i][j][1] = False
    dfs(cnt + 1, board)
    board = copy.deepcopy(copy_board)

    # 왼쪽으로 이동
    for k in range(n):
        for i in range(1, n):  # 왼쪽에 있는 것부터 움직인다.
            if board[k][i] is None:  # 빈칸은 움직일 필가 없다.
                continue
            col = i
            for j in range(i - 1, -1, -1):
                if board[k][j] is None:  # 이동할 칸이 빈칸이면
                    board[k][j] = board[k][col]
                    board[k][col] = None  # 현재 칸 빈칸으로 업데이트
                elif board[k][j][0] == board[k][col][0] and not board[k][j][1]:  # 값이 같고 아직 합쳐지지 않았다면
                    board[k][j][0] *= 2
                    board[k][j][1] = True
                    board[k][col] = None
                    break
                else:
                    break
                col -= 1
    for i in range(n):
        for j in range(n):
            if board[i][j] is not None:
                board[i][j][1] = False
    dfs(cnt + 1, board)
    board = copy.deepcopy(copy_board)

    # 오른쪽으로 이동
    for k in range(n):
        for i in range(n - 2, -1, - 1):  # 오른쪽에 있는 것부터 움직인다.
            if board[k][i] is None:  # 빈칸은 움직일 필가 없다.
                continue
            col = i
            for j in range(i + 1, n):
                if board[k][j] is None:  # 이동할 칸이 빈칸이면
                    board[k][j] = board[k][col]
                    board[k][col] = None  # 현재 칸 빈칸으로 업데이트
                elif board[k][j][0] == board[k][col][0] and not board[k][j][1]:  # 값이 같고 아직 합쳐지지 않았다면
                    board[k][j][0] *= 2
                    board[k][j][1] = True
                    board[k][col] = None
                    break
                else:
                    break
                col += 1
    for i in range(n):
        for j in range(n):
            if board[i][j] is not None:
                board[i][j][1] = False
    dfs(cnt + 1, board)


if __name__ == "__main__":
    n = int(input())  # 보드의 크기
    board = [list(map(int, input().split())) for _ in range(n)]

    # board 값 형태를 (값, flag- 합쳐졌는지 표시)로 바꾼다.
    answer = 0  # 가장 큰 블록 초기값
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                board[i][j] = None
            else:
                answer = max(answer, board[i][j])
                board[i][j] = [board[i][j], False]

    # bfs 탐색
    dfs(1, board)

    # 출력
    print(answer)
