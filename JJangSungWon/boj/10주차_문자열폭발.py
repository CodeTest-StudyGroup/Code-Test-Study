if __name__ == "__main__":
    a = "1234"
    string = input()
    word = input()
    q = list()
    for i in range(len(string)):
        if string[i] == word[-1]:  # 폭발 문자열이 있는지 확인
            if len(word) == 1:
                continue
            try:
                if "".join(map(str, q[-len(word) + 1:])) == word[:-1]:
                    for _ in range(len(word) - 1):
                        q.pop()
                else:
                    q.append(string[i])
            except:
                q.append(string[i])
        else:
            q.append(string[i])

    if len(q) == 0:
        print("FRULA")
    else:
        print("".join(map(str, q)))