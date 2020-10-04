def find(m, n, array):  # 4개 일치하는 블록 찾기
    flag = False
    temp = [[False] * n for _ in range(m)]
    for i in range(m - 1):
        for j in range(n - 1):
            if array[i][j] != "":
                if array[i][j] == array[i][j + 1] == array[i + 1][j] == array[i + 1][j + 1]:
                    temp[i][j], temp[i][j + 1], temp[i + 1][j], temp[i + 1][j + 1] = True, True, True, True
                    flag = True

    return temp, flag


def fill(m, n, array):
    for i in range(m - 2, -1, -1):
        for j in range(n):
            if array[i][j] != "":
                for k in range(i + 1, m):
                    if array[k][j] == "":
                        array[k][j] = array[k - 1][j]
                        array[k - 1][j] = ""
                    else:
                        break
    return array


def solution(m, n, board):
    # board 재구성
    array = [list(map(str, board[i].strip())) for i in range(m)]

    answer = 0
    while True:
        temp, flag = find(m, n, array)
        if not flag:
            break
        else:  # 블록 지우기
            for i in range(m):
                for j in range(n):
                    if temp[i][j] and array[i][j] != "":
                        answer += 1
                        array[i][j] = ""
        # 블록 지운 부분 채우기
        array = fill(m, n, array)

    return answer


if __name__ == "__main__":
    # print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
    print(solution(6, 6, ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]))
