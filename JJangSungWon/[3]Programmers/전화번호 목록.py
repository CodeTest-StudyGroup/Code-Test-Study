def solution(phone_book):
    for i in range(len(phone_book)):
        for j in range(len(phone_book)):
            if i != j:
                cnt = 0
                if len(phone_book[i]) <= len(phone_book[j]):
                    for k in range(len(phone_book[i])):
                        if phone_book[i][cnt] == phone_book[j][k]:
                            cnt += 1
                        else:
                            cnt = 0

                        if cnt == len(phone_book[i]):
                            return False
    return True


if __name__ == "__main__":
    print(solution(["119", "97674223", "1195524421"]))
