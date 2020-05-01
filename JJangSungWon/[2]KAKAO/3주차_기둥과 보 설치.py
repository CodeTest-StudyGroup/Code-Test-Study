from operator import itemgetter

answer = []


def check():
    for i in range(len(answer)):
        x, y, kind = answer[i][0], answer[i][1], answer[i][2]

        if kind == 0:  # 기둥
            if [x, y - 1, kind] in answer or [x - 1, y, 1] in answer or [x, y, 1] in answer:
                continue
            elif y == 0:
                continue
            else:
                return False
        else:  # 보
            if [x, y - 1, 0] in answer or [x + 1, y - 1, 0] in answer or (
                    [x - 1, y, 1] in answer and [x + 1, y, 1] in answer):
                continue
            else:
                return False
    return True


def delete(flag, x, y):  # 삭제 가능한지 확인
    answer.remove([x, y, flag])
    if not check():
        answer.append([x, y, flag])


def add(flag, x, y):  # 추가 가능한지 확인
    if flag == 0:  # 기둥
        if [x - 1, y, 1] in answer or [x, y, 1] in answer:  # 보 위에 기둥 설치
            return True
        elif y == 0:
            return True
        elif [x, y - 1, 0] in answer:
            return True
    else:  # 보
        if [x, y - 1, 0] in answer or [x + 1, y - 1, 0] in answer:  # 기둥 위에 보 설치
            return True
        elif [x - 1, y, 1] in answer and [x + 1, y, 1] in answer:  # 양 쪽 보
            return True

    return False


def solution(n, build_frame):
    # build_frame에 들어있는 값 순차적 실행
    for i in range(len(build_frame)):
        if build_frame[i][3] == 0:  # 삭제
            if delete(build_frame[i][2], build_frame[i][0], build_frame[i][1]):
                if [build_frame[i][0], build_frame[i][1], build_frame[i][2]] in answer:
                    answer.remove([build_frame[i][0], build_frame[i][1], build_frame[i][2]])
        else:  # 추가
            if add(build_frame[i][2], build_frame[i][0], build_frame[i][1]):
                answer.append([build_frame[i][0], build_frame[i][1], build_frame[i][2]])

    answer.sort(key=itemgetter(0, 1, 2))
    return answer


if __name__ == "__main__":
    print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))
