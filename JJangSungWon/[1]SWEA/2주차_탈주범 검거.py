def bfs(row, col, idx):
    global cnt, L
    visited = [(row, col)]
    dy, dx = [-1, 1, 0, 0], [0, 0, -1, 1]

    while idx != L:
        for _ in range(len(visited)):
            row, col = visited.pop(0)
            for i in range(4):
                new_row = row + dy[i]
                new_col = col + dx[i]
                if 0 <= new_row < N and 0 <= new_col < M:
                    if i == 0:  # 상
                        if data[row][col] in [1, 2, 4, 7] and data[new_row][new_col] in [1, 2, 5, 6] and (new_row, new_col) not in visited:
                            visited.append((new_row, new_col))
                            cnt += 1
                    elif i == 1:  # 하
                        if data[row][col] in [1, 2, 5, 6] and data[new_row][new_col] in [1, 2, 4, 7] and (new_row, new_col) not in visited:
                            visited.append((new_row, new_col))
                            cnt += 1
                    elif i == 2:  # 좌
                        if data[row][col] in [1, 3, 6, 7] and data[new_row][new_col] in [1, 3, 4, 5] and (new_row, new_col) not in visited:
                            visited.append((new_row, new_col))
                            cnt += 1
                    elif i == 3:  # 우
                        if data[row][col] in [1, 3, 4, 5] and data[new_row][new_col] in [1, 3, 6, 7] and (new_row, new_col) not in visited:
                            visited.append((new_row, new_col))
                            cnt += 1
            data[row][col] = 0
        idx += 1


if __name__ == "__main__":
    T = int(input())

    for tc in range(1, T + 1):
        N, M, R, C, L = map(int, input().split())
        data = [list(map(int, input().split())) for _ in range(N)]
        cnt = 1
        bfs(R, C, 1)
        print("#{} {}".format(tc, cnt))
