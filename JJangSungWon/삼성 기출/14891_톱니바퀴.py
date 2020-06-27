import copy


if __name__ == "__main__":

    # 바퀴 입력
    wheel = []
    for _ in range(4):
        wheel.append(list(map(int, input().strip())))

    # 회전 입력
    K = int(input())
    rotation = []
    for _ in range(K):
        rotation.append(list(map(int, input().split())))

    for k in range(K):
        index, direction = rotation[k]
        index -= 1

        if direction == 1:  # 시계 방향
            val = wheel[index].pop()
            wheel[index].insert(0, val)
            flag = 1
        else:
            val = wheel[index].pop(0)
            wheel[index].append(val)
            flag = -1

        original_flag = flag
        original_direction = direction
        # index 왼쪽
        for i in range(index - 1, -1, -1):
            if wheel[i][2] != wheel[i + 1][-2 + flag]:
                if direction == 1:  # 이전에 시계 방향
                    val = wheel[i].pop(0)
                    wheel[i].append(val)
                    flag = -1
                else:  # 이전에 반시계 방향
                    val = wheel[i].pop()
                    wheel[i].insert(0, val)
                    flag = 1
                direction *= -1
            else:
                break

        flag = original_flag
        direction = original_direction
        # index 오른쪽
        for i in range(index + 1, 4):
            if wheel[i][-2] != wheel[i - 1][2 + flag]:
                if direction == 1:  # 이전에 시계 방향
                    val = wheel[i].pop(0)
                    wheel[i].append(val)
                    flag = -1
                else:  # 이전에 반시계 방향
                    val = wheel[i].pop()
                    wheel[i].insert(0, val)
                    flag = 1
                direction *= -1
            else:
                break
    score = 0
    for i in range(4):
        if wheel[i][0] == 1:
            score += pow(2, i)
    print(score)
