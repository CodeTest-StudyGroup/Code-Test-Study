if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):

        K = int(input())
        data = [list(map(int, input().split())) for _ in range(4)]
        rotation = []

        for _ in range(K):
            rotation.append(list(map(int, input().split())))

        # 3번째가 옆에꺼랑 마주보는 부분
        for i in range(len(rotation)):

            index = rotation[i][0] - 1
            pre_value = data[index][-2]
            post_value = data[index][2]
            direction = rotation[i][1]

            for j in range(index - 1, -1, -1):  # 왼쪽
                if pre_value != data[j][2]:
                    pre_value = data[j][-2]
                    if direction == 1:  # 이전이 시계 방향 (반시계로 회전)
                        temp = data[j].pop(0)
                        data[j].append(temp)

                    else:  # 이전이 반시계 방향 (시계방향으로 회전)
                        temp = data[j].pop()
                        data[j].insert(0, temp)
                    direction *= -1
                else:
                    break

            direction = rotation[i][1]
            for j in range(index + 1, 4):  # 오른쪽
                if post_value != data[j][-2]:
                    post_value = data[j][2]
                    if direction == 1:  # 이전이 시계 방향 (반시계로 회전)
                        temp = data[j].pop(0)
                        data[j].append(temp)

                    else:  # 이전이 반시계 방향 (시계방향으로 회전)
                        temp = data[j].pop()
                        data[j].insert(0, temp)
                    direction *= -1
                else:
                    break

            if rotation[i][1] == 1:
                temp = data[index].pop()
                data[index].insert(0, temp)
            else:
                temp = data[index].pop(0)
                data[index].append(temp)

        total = 0
        for i in range(4):
            if i == 0 and data[i][0] == 1:
                total += 1
            elif data[i][0] == 1:
                total += pow(2, i)

        print("#{} {}".format(tc, total))
