import sys

sys.setrecursionlimit(10 ** 9)

# 윷놀이 지도
maps = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40]
p_1 = [10, 13, 16, 19, 25, 30, 35, 40]
p_2 = [20, 22, 24, 25, 30, 35, 40]
p_3 = [30, 28, 27, 26, 25, 30, 35, 40]


def dfs(idx, total, horse):
    global answer
    if idx == 10:
        answer = max(answer, total)
        return
    elif total + (10 - idx) * 40 < answer:  # 절대로 도달할 수 없는 경우
        return

    # 이동하는 위치에 다른 말이 있는지 확인
    for i in range(4):
        flag = True
        for j in range(4):
            if i == j:
                continue
            if horse[i][0] == 0:  # 일반 경로
                if horse[i][1] >= 21:
                    flag = False
                    break
                elif horse[i][1] + data[idx] >= 21:
                    pass
                elif horse[j][0] == 0:
                    if horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break
                elif horse[j][0] == 1:
                    if horse[i][1] + data[idx] == 5 and horse[j][1] == 0:
                        flag = False
                        break
                    elif horse[i][1] + data[idx] == 20 and horse[j][1] == 7:
                        flag = False
                        break
                elif horse[j][0] == 2:
                    if horse[i][1] + data[idx] == 10 and horse[j][1] == 0:
                        flag = False
                        break
                    elif horse[i][1] + data[idx] == 20 and horse[j][1] == 6:
                        flag = False
                        break
                elif horse[j][0] == 3:
                    if horse[i][1] + data[idx] == 15 and horse[j][1] == 0:
                        flag = False
                        break
                    elif horse[i][1] + data[idx] == 20 and horse[j][1] == 7:
                        flag = False
                        break
            elif horse[i][0] == 1:  # 10을 지나는 경로
                if horse[i][1] > 7:
                    flag = False
                    break
                elif horse[i][1] + data[idx] > 7:
                    pass
                elif horse[j][0] == 0:
                    if horse[i][1] + data[idx] == 7 and horse[j][1] == 20:
                        flag = False
                        break
                elif horse[j][0] == 1:
                    if horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break
                elif horse[j][0] == 2:
                    if horse[i][1] + data[idx] >= 4 and horse[i][1] + data[idx] - horse[j][1] == 1:
                        flag = False
                        break
                elif horse[j][0] == 3:
                    if horse[i][1] + data[idx] >= 4 and horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break
            elif horse[i][0] == 2:  # 20을 지나는 경로
                if horse[i][1] > 6:
                    flag = False
                    break
                elif horse[i][1] + data[idx] > 6:
                    pass
                elif horse[j][0] == 0:
                    if horse[i][1] + data[idx] == 6 and horse[j][1] == 20:
                        flag = False
                        break
                elif horse[j][0] == 1 or horse[j][0] == 3:
                    if horse[i][1] + data[idx] >= 3 and horse[i][1] + data[idx] - horse[j][1] == -1:
                        flag = False
                        break
                elif horse[j][0] == 2:
                    if horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break
            elif horse[i][0] == 3:  # 30을 지나는 경로
                if horse[i][1] > 7:
                    flag = False
                    break
                elif horse[i][1] + data[idx] > 7:
                    pass
                elif horse[j][0] == 0:
                    if horse[i][1] + data[idx] == 7 and horse[j][1] == 20:
                        flag = False
                        break
                elif horse[j][0] == 1:
                    if horse[i][1] + data[idx] >= 4 and horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break
                elif horse[j][0] == 2:
                    if horse[i][1] + data[idx] >= 4 and horse[i][1] + data[idx] - horse[j][1] == 1:
                        flag = False
                        break
                elif horse[j][0] == 3:
                    if horse[i][1] + data[idx] == horse[j][1]:
                        flag = False
                        break

        # 이동이 가능한 경우
        if flag:
            if horse[i][0] == 0:  # 기본 길
                temp = horse[i][1]
                if horse[i][1] >= 21:  # 이미 도착한 경우
                    continue
                elif data[idx] + horse[i][1] >= 21:  # 도착지점 도착
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total, horse)
                    horse[i][1] -= data[idx]
                elif data[idx] + horse[i][1] == 5:  # 10 경로
                    horse[i][0] = 1
                    horse[i][1] = 0
                    dfs(idx + 1, total + 10, horse)
                    horse[i][0] = 0
                    horse[i][1] = temp
                elif data[idx] + horse[i][1] == 10:  # 20 경로
                    horse[i][0] = 2
                    horse[i][1] = 0
                    dfs(idx + 1, total + 20, horse)
                    horse[i][0] = 0
                    horse[i][1] = temp
                elif data[idx] + horse[i][1] == 15:  # 30 경로
                    horse[i][0] = 3
                    horse[i][1] = 0
                    dfs(idx + 1, total + 30, horse)
                    horse[i][0] = 0
                    horse[i][1] = temp
                else:  # 쭉 갈 수 있는 경우
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total + maps[horse[i][1]], horse)
                    horse[i][1] -= data[idx]
            elif horse[i][0] == 1:  # 10을 지나는 경로
                if horse[i][1] > 7:
                    continue
                elif horse[i][1] + data[idx] > 7:  # 도착
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total, horse)
                    horse[i][1] -= data[idx]
                else:
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total + p_1[horse[i][1]], horse)
                    horse[i][1] -= data[idx]
            elif horse[i][0] == 2:  # 20을 지나는 경로
                if horse[i][1] > 6:
                    continue
                elif horse[i][1] + data[idx] > 6:  # 도착
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total, horse)
                    horse[i][1] -= data[idx]
                else:
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total + p_2[horse[i][1]], horse)
                    horse[i][1] -= data[idx]
            elif horse[i][0] == 3:  # 30을 지나는 경로
                if horse[i][1] > 7:
                    continue
                elif horse[i][1] + data[idx] > 7:  # 도착
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total, horse)
                    horse[i][1] -= data[idx]
                else:
                    horse[i][1] += data[idx]
                    dfs(idx + 1, total + p_3[horse[i][1]], horse)
                    horse[i][1] -= data[idx]


if __name__ == "__main__":
    data = list(map(int, input().split()))

    answer = 0

    dfs(0, 0, [[0, 0], [0, 0], [0, 0], [0, 0]])
    print(answer)
