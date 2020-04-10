alphabet = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]


def solution(name):
    name = list(name)

    answer = 0

    for i in range(len(name)):
        name[i] = ord(name[i]) - ord('A')

    for i in name:
        if i >= 14:
            answer += 26 - i
        else:
            answer += i

    cnt = 0
    current = 0
    name[0] = 0

    while sum(name) != 0:
        if current + 1 < len(name) and name[current + 1] != 0:
            current += 1
            cnt += 1
            name[current] = 0
        else:
            front_value, back_value = 0, 0
            for i in range(1, len(name)):
                value = current + i
                if value > len(name) - 1:
                    value %= len(name)

                if name[value] != 0:
                    front_value += 1
                    break
                else:
                    front_value += 1

            for i in range(1, len(name)):
                if name[current - i] != 0:
                    back_value += 1
                    break
                else:
                    back_value += 1

            if front_value != 0 and front_value <= back_value:
                cnt += front_value
                while front_value != 0:
                    if current + 1 > len(name) - 1:
                        current = (current + 1) % len(name)
                        front_value -= 1
                    else:
                        current += 1
                        front_value -= 1

                name[current] = 0
            else:
                cnt += back_value
                while back_value != 0:
                    if current - 1 < 0:
                        current = len(name) - 1
                        back_value -= 1
                    else:
                        current -= 1
                        back_value -= 1
                name[current] = 0

    answer += cnt
    return answer


if __name__ == "__main__":
    print(solution("STRING"))
