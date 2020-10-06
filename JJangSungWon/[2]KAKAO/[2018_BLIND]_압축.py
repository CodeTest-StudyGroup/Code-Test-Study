def solution(msg):
    alphabet_dict = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6, "G": 7, "H": 8, "I": 9, "J": 10, "K": 11,
                           "L": 12, "M": 13, "N": 14, "O": 15, "P": 16, "Q": 17, "R": 18, "S": 19, "T": 20, "U": 21,
                           "V": 22, "W": 23, "X": 24, "Y": 25, "Z": 26}
    answer = []
    pre_index = 0
    post_index = 1
    value = 27
    while post_index <= len(msg):
        if msg[pre_index:post_index] in alphabet_dict:
            if post_index + 1 > len(msg):
                answer.append(alphabet_dict[msg[pre_index:post_index]])
            post_index += 1
        else:
            answer.append(alphabet_dict[msg[pre_index:post_index - 1]])  # 이전 값의 색인 번호 삽입
            alphabet_dict[msg[pre_index:post_index]] = value
            value += 1
            pre_index = post_index - 1
            post_index = pre_index + 1
    return answer


if __name__ == "__main__":
    print(solution("KAKAO"))
    print(solution("TOBEORNOTTOBEORTOBEORNOT"))
    print(solution("ABABABABABABABAB"))
