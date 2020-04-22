import copy


answer = []


def dfs(arr, cnt, N, visited):
    global answer

    if cnt == N:
        temp = copy.deepcopy(visited)
        answer.append(temp)
        return

    for i in range(len(arr[cnt])):
        if arr[cnt][i] not in visited:
            visited.append(arr[cnt][i])
            dfs(arr, cnt + 1, N, visited)
            visited.remove(arr[cnt][i])


def solution(user_id, banned_id):
        global answer
        result = []

        for j in range(len(banned_id)):
            temp = []
            for i in range(len(user_id)):
                if len(user_id[i]) != len(banned_id[j]):
                    continue
                else:
                    for k in range(len(user_id[i])):
                        if user_id[i][k] == banned_id[j][k] or banned_id[j][k] == '*':
                            if k == len(user_id[i]) - 1:
                                temp.append(user_id[i])
                        else:
                            break
            result.append(temp)

        dfs(result, 0, len(banned_id), [])

        val = len(answer)
        check = 0
        for i in range(len(answer)):
            for j in range(i + 1, len(answer)):
                cnt = 0
                if i != j:
                    for m in range(len(answer[i])):
                        for n in range(len(answer[j])):
                            if answer[i][m] == answer[j][n]:
                                cnt += 1
                                break

                if cnt == len(banned_id):
                    check += 1
                    break

        val = val - check

        return val


if __name__ == "__main__":
    print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"]))
