dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

if __name__ == "__main__":

    T = int(input())
    for tc in range(1, T + 1):
        N, M, K = map(int, input().split())

        # 배양 용기의 크기가 무한하기 때문에 최대한으로 이동할 수 있는 K만큼 배열을 할당한다.
        arr = [[0] * (2 * K + M) for _ in range(K)] + [[0] * K + list(map(int, input().split())) + [0] * K for _ in range(N)] + [[0] * (2 * K + M) for _ in range(K)]

        # 1 ~ 10 이하의 정수의 생명력을 관리
        life_force = [list() for _ in range(11)]
        for i in range(K, K + N + 1):
            for j in range(K, K + M + 1):
                if arr[i][j] != 0:
                    life_force[arr[i][j]].append([i, j, arr[i][j]])  # 행, 열, 생명주기

        for _ in range(K):
            for i in range(10, 0, -1):  # 생명주기가 높은 것이 우선순위가 높으므로 생명주기 높은 순부터 탐색
                for j in range(len(life_force[i])):
                    if sum(life_force[i][j]) == -3000:
                        continue
                    elif life_force[i][j][2] > 0:  # 비활성
                        life_force[i][j][2] -= 1
                    elif life_force[i][j][2] == 0:  # 활성
                        r, c, value = life_force[i][j][0], life_force[i][j][1], life_force[i][j][2]
                        for k in range(4):
                            new_r, new_c = r + dy[k], c + dx[k]
                            if arr[new_r][new_c] == 0:
                                arr[new_r][new_c] = 1
                                life_force[i].append([new_r, new_c, i])
                        life_force[i][j][2] -= 1
                    elif life_force[i][j][2] == -i:  # 죽은 상태
                        life_force[i][j] = [-1000, -1000, -1000]  # 의미없는 값
                    else:
                        life_force[i][j][2] -= 1
                # 제거
                index = 0
                for _ in range(len(life_force[i])):
                    if sum(life_force[i][index]) == -3000 or life_force[i][index][2] == -i:
                        life_force[i].pop(index)
                        index -= 1
                    index += 1

        # 살아있는 줄기 세포 개수
        answer = 0
        for i in range(1, 11):
            for j in range(len(life_force[i])):
                if sum(life_force[i][j]) == -3000:
                    continue
                else:
                    answer += 1

        print("#{} {}".format(tc, answer))
