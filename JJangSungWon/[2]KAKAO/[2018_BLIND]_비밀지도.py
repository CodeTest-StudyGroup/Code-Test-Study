def get_binary_number(n, num):  # 숫자를 이진수로 변환
    result = ""
    while num:
        result = str(num % 2) + result
        num //= 2
    for _ in range(n, len(result), -1):  # 앞부분 0으로 채우기
        result = "0" + result
    return list(result)


def solution(n, arr1, arr2):
    array = [[None] * n for _ in range(n)]  # None으로 초기화
    # arr1 -> array, arr2 -> array
    for i in range(n):
        temp = get_binary_number(n, arr1[i])
        for j in range(n):
            if temp[j] == "1":
                array[i][j] = "#"
            elif temp[j] == "0" and array[i][j] != "#":
                array[i][j] = " "
        temp = get_binary_number(n, arr2[i])
        for j in range(n):
            if temp[j] == "1":
                array[i][j] = "#"
            elif temp[j] == "0" and array[i][j] != "#":
                array[i][j] = " "

    answer = []
    for i in range(n):
        answer.append("".join(map(str, array[i])))
    return answer


if __name__ == "__main__":
    print(solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]))
    # print(solution(6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]))