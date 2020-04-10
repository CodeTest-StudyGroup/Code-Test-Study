def game(idx, nations_score, probability):
    if idx == 6:
        # 점수 순서로 내림차순 정렬
        sorted_score = sorted(list(nations_score.items()), key=lambda x: x[1], reverse=True)

        # 동점 4명
        if sorted_score[0][1] == sorted_score[1][1] == sorted_score[2][1] == sorted_score[3][1]:
            for i in range(4):
                nations_probability[sorted_score[i][0]] += probability * 1 / 2  # 4팀중 2팀
            return
        # 동점 3명
        elif sorted_score[0][1] > sorted_score[1][1] == sorted_score[2][1] == sorted_score[3][1]:
            nations_probability[sorted_score[0][0]] += probability
            for i in range(1, 4):
                nations_probability[sorted_score[i][0]] += probability * 1 / 3  # 3팀중 1팀
            return
        elif sorted_score[0][1] == sorted_score[1][1] == sorted_score[2][1]:
            for i in range(3):
                nations_probability[sorted_score[i][0]] += probability * 2 / 3  # 3팀중 2팀
            return
        # 동점 2명
        elif sorted_score[0][1] > sorted_score[1][1] == sorted_score[2][1]:
            nations_probability[sorted_score[0][0]] += probability

            for i in range(1, 3):
                nations_probability[sorted_score[i][0]] += probability * 1 / 2  # 2팀중 1팀
            return
        # 동점자 없음
        else:
            for i in range(2):
                nations_probability[sorted_score[i][0]] += probability  # 상위 2팀
            return

    # brute force (모든 경우를 다한다)
    # A 승
    nations_score[data[idx][0]] += 3  # 승점 3점
    game(idx + 1, nations_score, probability * float(data[idx][2]))
    nations_score[data[idx][0]] -= 3  # 다시 승점 3점을 빼준다.

    # 무승부
    nations_score[data[idx][0]] += 1
    nations_score[data[idx][1]] += 1
    game(idx + 1, nations_score, probability * float(data[idx][3]))
    nations_score[data[idx][0]] -= 1
    nations_score[data[idx][1]] -= 1

    # B 승
    nations_score[data[idx][1]] += 3
    game(idx + 1, nations_score, probability * float(data[idx][4]))
    nations_score[data[idx][1]] -= 3


if __name__ == "__main__":

    nations = input().split()
    # index 값 유지를 위해서 dictionary 선언
    nations_score, nations_probability = {}, {}
    data = []

    # dictionary 초기화
    for key in nations:
        nations_score[key], nations_probability[key] = 0, 0

    for _ in range(6):
        temp = list(input().split())
        data.append(temp)

    # 게임 번호, 점수, 확률
    # 게임 번호는 0, 1, 2, 3, 4, 5까지 존재. 6일때 종료
    # 점수는 각각의 나라에 해당하는 점수 저장
    # 확률은 계속 곱하면서 최종값을 찾기때문에 초기값 1 설정
    game(0, nations_score, 1)

    # print
    for key in nations:
        print(nations_probability[key])
