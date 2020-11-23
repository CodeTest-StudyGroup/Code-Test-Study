if __name__ == "__main__":
    n = int(input())  # 단어의 개수
    word = [list(input().strip()) for _ in range(n)]  # 단어 입력

    v = dict()  # 각 알파벳의 가치 계산
    visited = set()
    for i in range(len(word)):
        for j in range(len(word[i])):
            if word[i][j] not in visited:
                v[word[i][j]] = pow(10, (len(word[i]) - j - 1))
                visited.add(word[i][j])
            else:
                v[word[i][j]] += pow(10, (len(word[i]) - j - 1))

    # 가치가 높은 수부터 값 대입
    value = []
    for key in v.keys():
        value.append([v[key], key])

    # 가치순으로 내림차순 정렬
    value.sort(reverse=True)

    selected = dict()
    d = 9
    for i in range(len(value)):
        selected[value[i][1]] = d
        d -= 1

    # word 숫자로 변환
    for i in range(len(word)):
        for j in range(len(word[i])):
            word[i][j] = selected[word[i][j]]

    result = 0
    for i in range(len(word)):
        result += int("".join(map(str, word[i])))
    print(result)