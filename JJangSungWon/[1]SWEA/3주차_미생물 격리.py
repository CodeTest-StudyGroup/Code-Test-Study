from operator import itemgetter
import copy

if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):

        N, M, K = map(int, input().split())
        arr = [[False] * N for _ in range(N)]
        total = 0

        for _ in range(K):
            row, col, num, direction = map(int, input().split())
            arr[row][col] = [(num, direction)]
            total += num

        while M > 0:
            # 이동
            visited = []
            for i in range(N):
                for j in range(N):
                    if not arr[i][j] or (i, j) in visited:
                        continue
                    else:
                        if arr[i][j][0][1] == 1 and i - 1 >= 0:  # 상
                            if not arr[i - 1][j]:
                                arr[i - 1][j] = [(arr[i][j][0][0], arr[i][j][0][1])]
                                visited.append((i - 1, j))
                            else:
                                arr[i - 1][j].append((arr[i][j][0][0], arr[i][j][0][1]))
                        if arr[i][j][0][1] == 2 and i + 1 < N:  # 하
                            if not arr[i + 1][j]:
                                arr[i + 1][j] = [(arr[i][j][0][0], arr[i][j][0][1])]
                                visited.append((i + 1, j))
                            else:
                                arr[i + 1][j].append((arr[i][j][0][0], arr[i][j][0][1]))
                        if arr[i][j][0][1] == 3 and j - 1 >= 0:  # 좌
                            if not arr[i][j - 1]:
                                arr[i][j - 1] = [(arr[i][j][0][0], arr[i][j][0][1])]
                                visited.append((i, j - 1))
                            else:
                                arr[i][j - 1].append((arr[i][j][0][0], arr[i][j][0][1]))
                        if arr[i][j][0][1] == 4 and j + 1 < N:  # 우
                            if not arr[i][j + 1]:
                                arr[i][j + 1] = [(arr[i][j][0][0], arr[i][j][0][1])]
                                visited.append((i, j + 1))
                            else:
                                arr[i][j + 1].append((arr[i][j][0][0], arr[i][j][0][1]))
                        arr[i][j].pop(0)

            # 계산
            for i in range(N):
                for j in range(N):
                    if (i == 0 or j == 0 or i == N - 1 or j == N - 1) and arr[i][j] != False and len(arr[i][j]) == 1:
                        num, direction = arr[i][j][0][0], arr[i][j][0][1]
                        total -= num - num // 2
                        num //= 2

                        if direction % 2 == 0:
                            direction -= 1
                        else:
                            direction += 1
                        arr[i][j] = [(num, direction)]
                    elif arr[i][j] != 0 and len(arr[i][j]) > 1:
                        arr[i][j].sort(key=itemgetter(0), reverse=True)
                        sub_total, direction = 0, arr[i][j][0][1]
                        for k in range(len(arr[i][j])):
                            sub_total += arr[i][j][k][0]
                        arr[i][j] = [(sub_total, direction)]

            M -= 1
        print("#{} {}".format(tc, total))
