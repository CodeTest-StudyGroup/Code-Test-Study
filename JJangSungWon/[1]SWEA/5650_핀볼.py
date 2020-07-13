# 상 하 좌 우
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


def wall(row, col, dir):  # 벽을 만났을때
    if dir == 0 or dir == 2:
        return dir + 1
    else:
        return dir - 1


def change(row, col, dir):  # 블럭을 만났을때
    if dir == 0:  # 상
        val = [-1, 1, 3, 2, 1, 1]  # [의미없는 값, 하, 우, 좌, 하, 하]
        return val[arr[row][col]]
    elif dir == 1:  # 하
        val = [-1, 3, 0, 0, 2, 0]
        return val[arr[row][col]]
    elif dir == 2:  # 좌
        val = [-1, 0, 1, 3, 3, 3]
        return val[arr[row][col]]
    elif dir == 3:  # 우
        val = [-1, 2, 2, 1, 0, 2]
        return val[arr[row][col]]


if __name__ == "__main__":
    T = int(input())  # 테스트 케이스의 개수
    for test_case in range(1, 1 + T):
        N = int(input())  # 핀볼 전체 크기 행, 열 정보

        # 테두리 추가
        arr = [[5] * (N + 2)] + [[5] + list(map(int, input().split())) + [5] for _ in range(N)] + [[5] * (N + 2)]

        # 웜홀 정보 저장
        dic = {}
        for i in range(1, N + 1):
            for j in range(1, N + 1):
                if 6 <= arr[i][j] <= 10:
                    try:
                        dic[arr[i][j]].append([i, j])
                    except:
                        dic[arr[i][j]] = [[i, j]]

        # 탐색
        max_score = 0
        for r in range(1, N + 1):
            for c in range(1, N + 1):
                if arr[r][c] == 0:
                    for d in range(4):  # 상(0), 하(1), 좌(2), 우(3)
                        score = 0
                        y, x = r + dy[d], c + dx[d]
                        while True:  # 재귀를 돌리면 메모리 초과가 발생하여 반복문으로 구현하였다.
                            if (y, x) == (r, c) or arr[y][x] == -1:  # 시작점, 블랙홀
                                break

                            # 블록
                            elif arr[y][x] in range(1, 5):
                                d = change(y, x, d)
                                score += 1

                            # 벽
                            elif arr[y][x] == 5:
                                d = wall(y, x, d)
                                score += 1

                            # 웜홀
                            elif arr[y][x] in range(6, 11):
                                value = arr[y][x]
                                for row, col in dic[value]:
                                    if row != y or col != x:
                                        y, x = row, col
                                        break

                            # 진행
                            y, x = y + dy[d], x + dx[d]

                        # 갱신
                        max_score = max(max_score, score)

        print('#{} {}'.format(test_case, max_score))
