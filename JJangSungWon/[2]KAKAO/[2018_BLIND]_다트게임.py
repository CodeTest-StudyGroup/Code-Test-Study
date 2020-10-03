def find_order(arr):
    result = []
    # 숫자 찾기
    result.append(arr[0])
    index = 1
    while index < len(arr):
        if "0" <= arr[index] <= "9":
            result[0] += arr[index]
        else:
            break
        index += 1

    # S, D, T 삽입
    result.append(arr[index])
    index += 1
    # *, #이 있으면 삽입 아니면 종료
    if index < len(arr) and arr[index] in ["*", "#"]:
        result.append(arr[index])
        index += 1
    return result, index


def solution(dartResult):
    answer = []  # 1 ~ 3번째 다트 결과를 저장한다.

    # 첫 번째 다트
    first, index = find_order(dartResult)
    for i in range(len(first)):
        if i == 0:
            answer.append(int(first[0]))
        elif i == 1:
            if first[i] == "D":
                answer[0] = int(pow(answer[0], 2))
            elif first[i] == "T":
                answer[0] = int(pow(answer[0], 3))
        elif i == 2:
            if first[i] == "*":
                answer[0] *= 2
            else:
                answer[0] *= -1

    # 두 번째 다트
    dartResult = dartResult[index:]
    second, index = find_order(dartResult)
    for i in range(len(second)):
        if i == 0:
            answer.append(int(second[0]))
        elif i == 1:
            if second[i] == "D":
                answer[1] = int(pow(answer[1], 2))
            elif second[i] == "T":
                answer[1] = int(pow(answer[1], 3))
        elif i == 2:
            if second[i] == "*":
                answer[0] *= 2
                answer[1] *= 2
            else:
                answer[1] *= -1

    # 세 번째 다트
    dartResult = dartResult[index:]
    thrid, index = find_order(dartResult)
    for i in range(len(thrid)):
        if i == 0:
            answer.append(int(thrid[0]))
        elif i == 1:
            if thrid[i] == "D":
                answer[2] = int(pow(answer[2], 2))
            elif thrid[i] == "T":
                answer[2] = int(pow(answer[2], 3))
        elif i == 2:
            if thrid[i] == "*":
                answer[1] *= 2
                answer[2] *= 2
            else:
                answer[2] *= -1

    return sum(answer)
