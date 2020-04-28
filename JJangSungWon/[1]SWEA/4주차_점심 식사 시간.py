import itertools


if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):

        N = int(input())
        data = [list(map(int, input().split())) for _ in range(N)]

        # 입구 위치, 사람 위치
        door, temp = [], []
        for i in range(N):
            for j in range(N):
                if data[i][j] >= 2:
                    door.append([i, j, data[i][j]])
                elif data[i][j] == 1:
                    temp.append([i, j])

        arr = [0, 1]
        permutations = list(itertools.product(arr, repeat=len(temp)))

        min_time = 1000000000000
        for k in range(len(permutations)):
            door_1, door_2 = [], []
            for m in range(len(permutations[k])):
                if permutations[k][m] == 0:
                    door_1.append(abs(temp[m][0] - door[0][0]) + abs(temp[m][1] - door[0][1]) + 1)
                else:
                    door_2.append(abs(temp[m][0] - door[1][0]) + abs(temp[m][1] - door[1][1]) + 1)

            stair_1, stair_2 = [], []
            time = 0
            while True:
                # 1칸씩 이동 및 계단 도착 여부 확인
                for i in range(len(door_1)):
                    if door_1[i] >= 0:
                        door_1[i] -= 1
                        if door_1[i] == -1:
                            stair_1.append([i, door[0][2]])

                for i in range(len(door_2)):
                    if door_2[i] >= 0:
                        door_2[i] -= 1
                        if door_2[i] == -1:
                            stair_2.append([i, door[1][2]])

                # 각 계단 인원 수
                stair_1.sort(key=lambda item: item[1])
                people_1, people_2 = [0] * 11, [0] * 11
                for i in range(len(stair_1)):
                    people_1[stair_1[i][1]] += 1

                stair_2.sort(key=lambda item: item[1])
                for i in range(len(stair_2)):
                    people_2[stair_2[i][1]] += 1

                # 계단 이동
                val = 0
                for i in range(len(stair_1)):
                    if stair_1[i][1] == 0:
                        continue
                    elif val < 3:
                        stair_1[i][1] -= 1
                        val += 1

                val = 0
                for i in range(len(stair_2)):
                    if stair_2[i][1] == 0:
                        continue
                    elif val < 3:
                        stair_2[i][1] -= 1
                        val += 1

                time += 1

                flag = 1
                if sum(door_1) == len(door_1) * - 1 and sum(door_2) == len(door_2) * -1:
                    cnt_1 = 0
                    for i in range(len(stair_1)):
                        if stair_1[i][1] != 0:
                            break
                        else:
                            cnt_1 += 1

                    cnt_2 = 0
                    for i in range(len(stair_2)):
                        if stair_2[i][1] != 0:
                            break
                        else:
                            cnt_2 += 1

                    if cnt_1 == len(stair_1) and cnt_2 == len(stair_2):
                        flag = 0

                if flag == 0:
                    break
            min_time = min(min_time, time)
        print("#{} {}".format(tc, min_time))
