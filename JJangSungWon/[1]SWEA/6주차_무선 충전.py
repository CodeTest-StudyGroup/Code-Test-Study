if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):
        M, A = map(int, input().split())  # 총 이동 시간, BC의 개수
        user1 = list(map(int, input().split()))  # user1 이동 정보
        user2 = list(map(int, input().split()))  # user2 이동 정보
        AP = [list(map(int, input().split())) for _ in range(A)]  # BC 정보

        arr = [[0] * 11 for _ in range(11)]  # 전체 지도

        charge = 0  # 충전량

        user1_position = [1, 1]
        user2_position = [10, 10]

        # 초기 상태
        user1.insert(0, 0)
        user2.insert(0, 0)

        move = [[0, 0], [0, -1], [1, 0], [0, 1], [-1, 0]]  # 이동X, 상, 우, 하, 좌
        # 이동 시작
        for i in range(M + 1):
            user1_position = [user1_position[0] + move[user1[i]][0], user1_position[1] + move[user1[i]][1]]
            user2_position = [user2_position[0] + move[user2[i]][0], user2_position[1] + move[user2[i]][1]]

            # user1, user2 가능한 경우 찾기
            user1_possible = []
            user2_possible = []
            for j in range(A):
                if abs(user1_position[0] - AP[j][0]) + abs(user1_position[1] - AP[j][1]) <= AP[j][2]:  # user1
                    user1_possible.append(j)
                if abs(user2_position[0] - AP[j][0]) + abs(user2_position[1] - AP[j][1]) <= AP[j][2]:  # user2
                    user2_possible.append(j)

            max_sum = -1
            # 최상의 경우 선택(완탐)
            if len(user1_possible) == 0 and len(user2_possible) == 0:
                continue
            elif len(user1_possible) == 0 and len(user2_possible) != 0:
                for m in user2_possible:
                    max_sum = max(max_sum, AP[m][3])
            elif len(user1_possible) != 0 and len(user2_possible) == 0:
                for m in user1_possible:
                    max_sum = max(max_sum, AP[m][3])
            else:
                for m in user1_possible:
                    for n in user2_possible:
                        if m == n:  # 겹치는 경우
                            max_sum = max(max_sum, AP[m][3])
                        else:
                            max_sum = max(max_sum, AP[m][3] + AP[n][3])

            charge += max_sum

        print("#{} {}".format(tc, charge))
