from collections import Counter


def solution(str1, str2):
    str1_list = []
    str2_list = []

    # str1을 두 글자씩 끊기
    for i in range(len(str1) - 1):
        if ("a" <= str1[i] <= "z" or "A" <= str1[i] <= "Z") and ("a" <= str1[i + 1] <= "z" or "A" <= str1[i + 1] <= "Z"):
            str1_list.append(str1[i].upper() + str1[i + 1].upper())

    # str2을 두 글자씩 끊기
    for i in range(len(str2) - 1):
        if ("a" <= str2[i] <= "z" or "A" <= str2[i] <= "Z") and ("a" <= str2[i + 1] <= "z" or "A" <= str2[i + 1] <= "Z"):
            str2_list.append(str2[i].upper() + str2[i + 1].upper())

    if len(str1_list) == 0 and len(str2_list) == 0:  # 모두 공집합
        return 65536

    # 자카드 유사도 계산
    str1_count = Counter(str1_list)
    str2_count = Counter(str2_list)
    similarity = {}
    for key in str1_count.keys():
        if key not in similarity:
            similarity[key] = str1_count[key]

    for key in str2_count.keys():
        if key not in similarity:
            similarity[key] = str2_count[key]
        else:
            if similarity[key] < str2_count[key]:
                similarity[key] = str2_count[key]

    # 전체 개수 파악
    cnt = 0
    for key in similarity:
        cnt += similarity[key]

    # 일치하는 값 파악
    str1_set = set(str1_list)
    str2_set = set(str2_list)
    inter_value = str1_set & str2_set
    same_cnt = 0
    for index in inter_value:
        same_cnt += str1_list.count(index)
        same_cnt += str2_list.count(index)
    for key in similarity:
        if key in inter_value:
            same_cnt -= similarity[key]

    return int(same_cnt / cnt * 65536)


if __name__ == "__main__":
    print(solution("FRANCE", "french"))
    print(solution("handshake", "shake hands"))
    print(solution("aa1+aa2", "AAAA12"))
    print(solution("E=M*C^2", "e=m*c^2"))