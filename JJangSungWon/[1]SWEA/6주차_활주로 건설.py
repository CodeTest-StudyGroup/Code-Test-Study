if __name__ == "__main__":

    T = int(input())  # 총 테스트 케이스 개수

    for tc in range(1, T + 1):

        # input
        N, X = map(int, input().split())
        arr = [list(map(int, input().split())) for _ in range(N)]
        cnt = 0

        # 가로
        for i in range(N):
            temp = [arr[i][0], 1, True]  # 첫 행 첫 원소값, 개수, 첫 번째 시작 지점 여부
            flag = True
            for j in range(1, N):
                if arr[i][j] == temp[0]:
                    temp[1] += 1  # 개수 1개 증가
                elif arr[i][j] > temp[0] and arr[i][j] - temp[0] == 1:
                    if temp[1] >= X:
                        temp = [arr[i][j], 1, False]
                    else:
                        flag = False
                        break
                elif arr[i][j] < temp[0] and temp[0] - arr[i][j] == 1 and j + X <= N:
                    if sum(arr[i][j:j + X]) == X * arr[i][j]:
                        temp = [arr[i][j], -X + 1, False]
                    else:
                        flag = False
                        break
                else:  # 차이가 1이 아닌 경우
                    flag = False
                    break

            if flag:
                cnt += 1

        # 세로
        for i in range(N):
            temp = [arr[0][i], 1, True]  # 첫 열 첫 원소값, 개수, 첫 번째 시작 지점 여부
            flag = True
            for j in range(1, N):
                if arr[j][i] == temp[0]:
                    temp[1] += 1
                elif arr[j][i] > temp[0] and arr[j][i] - temp[0] == 1:
                    if temp[1] >= X:
                        temp = [arr[j][i], 1, False]
                    else:
                        flag = False
                        break
                elif arr[j][i] < temp[0] and temp[0] - arr[j][i] == 1 and j + X <= N:
                    sub_sum = 0
                    for k in range(X):
                        sub_sum += arr[j + k][i]

                    if sub_sum == X * arr[j][i]:
                        temp = [arr[j][i], -X + 1, False]
                    else:
                        flag = False
                        break
                else:
                    flag = False
                    break

            if flag:
                cnt += 1

        print("#{} {}".format(tc, cnt))
