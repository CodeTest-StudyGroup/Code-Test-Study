def solution(s):
    answer = []

    temp = list(map(str, s.split("}")))
    temp = temp[:-2]
    string = ""

    for i in range(len(temp)):
        for j in range(len(temp[i])):
            if temp[i][j] == '{':
                continue
            else:
                if temp[i][j] == ",":
                    if j != 0:
                        string += " "
                    else:
                        continue
                else:
                    string += temp[i][j]
        temp[i] = string
        string = ""

    for i in range(len(temp)):
        temp[i] = list(map(str, temp[i].split(" ")))

    temp.sort(key=lambda k:len(k))

    for i in range(len(temp)):
        for j in range(len(temp[i])):
            if int(temp[i][j]) not in answer:
                answer.append(int(temp[i][j]))
    return answer


if __name__ == "__main__":
    print(solution("{{20,111},{111}}"))
