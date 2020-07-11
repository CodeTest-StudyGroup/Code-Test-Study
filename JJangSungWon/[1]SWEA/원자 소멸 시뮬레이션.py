# SW Expert Academy 5648

d = [(0.5, 0), (-0.5, 0), (0, -0.5), (0, 0.5)]  # 상, 하, 좌, 우


def move(i):  # 좌표 이동
    dy, dx = d[i[2]]
    return [i[0] + dx, i[1] + dy, i[2], i[3]]


if __name__ == "__main__":
    T = int(input())  # 테스트 케이스의 개수
    for tc in range(1, T + 1):
        energy = 0  # 방출하는 에너지의 총합
        N = int(input())  # 원자들의 수
        arr = []  # 원자 정보 저장(x위치, y위치, 이동 방향, 보유 에너지)
        for _ in range(N):
            arr.append(list(map(int, input().split())))

        for _ in range(4000):
            if len(arr) <= 1:  # 충돌 가능성이 없는 경우
                break

            # 좌표 이동
            arr = list(map(move, arr))

            # list -> ditcionary로 변환
            dic = {}
            for i in range(len(arr)):
                x, y, direction, k = arr[i]
                if (x, y) not in dic.keys():
                    dic[(x, y)] = [arr[i]]
                else:
                    dic[(x, y)].append(arr[i])
            arr = []  # arr 변환 후 공백처리

            # 충돌 확인
            for key in dic.keys():
                if len(dic[key]) >= 2:  # 충돌이 일어난 경우
                    for value in dic[key]:
                        energy += value[3]
                else:  # 충돌이 일어나지 않은 경우
                    x, y = dic[key][0][0], dic[key][0][1]

                    if x > 1000 or y > 1000 or x < -1000 or y < -1000:
                        continue
                    else:
                        arr.append(dic[key][0])  # 계속 확인해볼 가치가 있는 경우

        print("#{} {}".format(tc, energy))
