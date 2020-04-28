def solution(s):
    s = list(map(str, str(s).strip()))

    # 압축하지 않은 값을 초깃값으로 설정
    answer = len(s)
    for i in range(1, len(s)):
        temp = []
        cnt = 1  # 갯수
        start = 0
        for j in range(0, len(s), i):
            if s[j:j + i] == s[j + i:j + i + i]:
                cnt += 1
                start = j + i
            else:
                if cnt != 1:
                    temp.extend(str(cnt))
                temp.extend(s[start: j + i])
                cnt = 1
                start = j + i

        answer = min(answer, len(temp))

    return answer


if __name__ == "__main__":
    print(solution("xababcdcdababcdcd"))
