# 오른쪽 대각선(아), 왼쪽 대각선(아), 왼쪽 대각선(위), 오른쪽 대각선(위)
dy = [1, 1, -1, -1]
dx = [1, -1, -1, 1]


def dfs(cnt, row, col, value, d):
    global max_val, start_y, start_x

    if cnt != 0 and (row, col) == (start_y, start_x):
        max_val = max(max_val, cnt)
    else:
        for i in range(4):
            new_row = row + dy[i]
            new_col = col + dx[i]

            if d == 0 and i in [2, 3]:  # 오른쪽 아래 (왼쪽 위, 오른쪽 위 금지)
                continue
            elif d == 1 and i in [0, 3]:  # 왼쪽 아래(오른쪽 아래, 오른쪽 위 금지)
                continue
            elif d == 2 and i in [0, 1]:  # 왼쪽 위(오른쪽 아래, 왼쪽 아래 금지)
                continue
            elif d == 3 and i in [0, 1, 2]:  # 오른쪽 위(오른쪽 위만 가능)
                continue

            if 0 <= new_row < N and 0 <= new_col < N and (new_row, new_col) and data[new_row][new_col] not in value:
                value.append(data[new_row][new_col])
                dfs(cnt + 1, new_row, new_col, value, i)
                value.remove(data[new_row][new_col])


if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):

        N = int(input())
        data = []

        for _ in range(N):
            data.append(list(map(int, input().split())))

        max_val = -1
        for i in range(N):
            for j in range(1, N - 1):
                value = []
                # visited = []
                start_y, start_x = i, j
                dfs(0, i, j, value, 0)

        print("#{0} {1}".format(tc, max_val))
