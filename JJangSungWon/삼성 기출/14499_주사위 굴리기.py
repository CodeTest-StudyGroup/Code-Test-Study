# boj 14499
# blog: jjangsungwon.tistory.com


"""
   동쪽 이동   서쪽 이동  북쪽 이동  남쪽 이동
    1 -> 3     1 -> 4    1 -> 2    1 -> 5
    2 -> 2     2 -> 2    2 -> 6    2 -> 1
    3 -> 6     3 -> 1    3 -> 3    3 -> 3
    4 -> 1     4 -> 6    4 -> 4    4 -> 4
    5 -> 5     5 -> 5    5 -> 1    5 -> 6
    6 -> 4     6 -> 3    6 -> 5    6 -> 2
"""


def move(n, arr):  # 주사위 변화
    if n == 1:    # 동
        return [0, arr[3], arr[2], arr[6], arr[1], arr[5], arr[4]]
    elif n == 2:  # 서
        return [0, arr[4], arr[2], arr[1], arr[6], arr[5], arr[3]]
    elif n == 3:  # 북
        return [0, arr[2], arr[6], arr[3], arr[4], arr[1], arr[5]]
    elif n == 4:  # 남
        return [0, arr[5], arr[1], arr[3], arr[4], arr[6], arr[2]]


if __name__ == "__main__":

    # input
    N, M, y, x, K = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(N)]
    order = list(map(int, input().split()))

    dice = [0] * 7  # 주사위

    dy = [0, 0, 0, -1, 1]
    dx = [0, 1, -1, 0, 0]

    # 명령 수행
    for i in range(len(order)):
        if y + dy[order[i]] < 0 or y + dy[order[i]] >= N or x + dx[order[i]] < 0 or x + dx[order[i]] >= M:
            continue
        else:
            x, y = x + dx[order[i]], y + dy[order[i]]  # 좌표 이동
            dice = move(order[i], dice)  # 주사위 이동

            if arr[y][x] == 0:
                arr[y][x] = dice[6]  # 주사위 -> 칸
            else:
                dice[6] = arr[y][x]  # 칸 -> 주사위
                arr[y][x] = 0  # 칸에 있는 수 0으로 수정

            print(dice[1])
