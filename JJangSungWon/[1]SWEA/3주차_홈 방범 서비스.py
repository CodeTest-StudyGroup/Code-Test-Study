def cal(k):
    return k * k + (k - 1) * (k - 1)


def home(row, col):
    global max_cnt

    for k in range(1, N + 3):  # N + 1까지하면 마지막 케이스가 안된다. (9,9) - > (19, 19)로 못간다.
        cost, cnt = 0, 0
        for data in check:
            if abs(data[0] - row) + abs(data[1] - col) < k:  # 거리 확인
                cost += M
                cnt += 1

        if cost >= cal(k) and cnt > max_cnt:  # 손해 확인
            max_cnt = cnt


if __name__ == "__main__":

    T = int(input())  # Test Case

    for tc in range(1, T + 1):
        N, M = map(int, input().split())
        arr = [list(map(int, input().split())) for _ in range(N)]

        check = []  # 1인 집 저장
        for i in range(N):
            for j in range(N):
                if arr[i][j]:
                    check.append((i, j))

        # 모든 경우를 확인한다.
        max_cnt = -1
        for i in range(N):
            for j in range(N):
                home(i, j)

        print("#{} {}".format(tc, max_cnt))
