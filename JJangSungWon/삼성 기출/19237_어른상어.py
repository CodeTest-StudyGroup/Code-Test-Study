# 상, 하, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

if __name__ == "__main__":
    n, m, k = map(int, input().split())
    array = [list(map(int, input().split())) for _ in range(n)]
    direction = list(map(int, input().split()))  # 각 상어의 방향
    shark = {}  # 상어 정보를 dictionary 형태로 저장
    for i in range(n):
        for j in range(n):
            if array[i][j] != 0:
                shark[array[i][j]] = [i, j, direction[array[i][j] - 1]]  # 위치와 방향 정보 저장
            array[i][j] = None
    dir = [list(map(int, input().split())) for _ in range(m * 4)]  # 각 상어의 방향 우선순위 정보 입력

    time = -1
    while time <= 1000:
        # 1번 상어만 남으면 경우 종료
        if len(shark) == 1:
            print(time)
            exit(0)

        # 각 상어의 냄새를 뿌립니다.
        keys = list(shark.keys())
        keys.sort()  # 번호가 낮은 것 부터 먼저 처리 하기 위해서 정렬
        for index in keys:
            if array[shark[index][0]][shark[index][1]] is None:  # 빈칸
                array[shark[index][0]][shark[index][1]] = [index, k]  # 상어 번호, 남은 냄새 시간 입력
            elif array[shark[index][0]][shark[index][1]][0] == index:  # 자기 냄새가 있던 칸
                array[shark[index][0]][shark[index][1]] = [index, k]
            else:  # 이동할 수 없으므로 삭제
                del shark[index]

        # 상어 이동
        keys = list(shark.keys())
        keys.sort()
        for index in keys:
            x, y, d = shark[index]  # 위치, 방향
            # 해당 상어의 방향 우선 순위에 맞게 빈칸 탐색
            flag_blank = False
            for i in dir[(index - 1) * 4 + (d - 1)]:
                nx, ny, nd = x + dx[i - 1], y + dy[i - 1], i
                if 0 <= nx < n and 0 <= ny < n:
                    if array[nx][ny] is None:  # 빈칸이면
                        flag_blank = True  # 빈칸을 찾은 상황
                        shark[index] = [nx, ny, nd]
                        break
            flag_same = False
            if not flag_blank:  # 빈칸이 없었던 경우
                for i in dir[(index - 1) * 4 + (d - 1)]:
                    nx, ny, nd = x + dx[i - 1], y + dy[i - 1], i
                    if 0 <= nx < n and 0 <= ny < n:
                        if array[nx][ny][0] == index:  # 똑같은 냄새 냄새
                            flag_same = True  # 똑같은 냄새를 찾은 상황
                            shark[index] = [nx, ny, nd]
                            break
            else:
                continue
            if not flag_same:  # 똑같은 냄새도 없던 경우
                del shark[index]  # 삭제

        # 상어 냄새 1 감소
        for i in range(n):  # 냄새 시간 1초 감소
            for j in range(n):
                if array[i][j] is not None:
                    array[i][j][1] -= 1
                    if array[i][j][1] == 0:  # 냄새가 0이면 삭제
                        array[i][j] = None

        time += 1
    # 시간이 1,000 초가 넘으면 -1 출력
    print(-1)
