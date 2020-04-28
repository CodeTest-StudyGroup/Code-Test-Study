def parentheses_balance_check(value):  # 균형잡힌 괄호 문자열 체크
    cnt_1, cnt_2 = 0, 0
    for i in range(len(value)):
        if value[i] == "(":
            cnt_1 += 1
        else:
            cnt_2 += 1

    if cnt_1 == cnt_2:
        return 1
    else:
        return 0


def parentheses_right_check(value):  # 올바른 괄호 문자열 체크
    stack = []
    for i in range(len(value)):
        if value[i] == "(":
            stack.append(value[i])
        else:
            if len(stack) == 0:
                return 0
            else:
                stack.pop()

    if len(stack) == 0:
        return 1
    else:
        return 0


def u_v_return(arr):  # 균형잡힌 괄호 문자열로 나누기
    if len(arr) == 0:
        return ""
    else:
        temp = []
        for i in range(len(arr)):
            if i != 0 and parentheses_balance_check("".join(map(str, temp))):
                u, v = "".join(map(str, temp)), "".join(map(str, arr[i:]))
                return u, v
            else:
                temp.append(arr[i])
                if i == len(arr) - 1:
                    u, v = "".join(map(str, temp)), ""
                    return u, v


def solution(p):
    if p == "":
        return ""
    elif parentheses_right_check(p):  # 입력이 올바른 괄호 문자열인 경우
        return p
    else:
        answer = ""
        u, v = u_v_return(p)

        if parentheses_right_check(u):  # u가 올바른 문자열인 경우
            return u + solution(v)
        else:  # u가 올바른 문자열이 아닌 경우
            answer += "("
            answer += solution(v)
            answer += ")"
            u = list(map(str, u.strip()))
            u.pop(0), u.pop()  # 첫 번째와 마지막 문자 제거
            for i in range(len(u)):
                if u[i] == "(":
                    u[i] = ")"
                else:
                    u[i] = "("
            answer += "".join(map(str, u))

        return answer


if __name__ == "__main__":
    print(solution(")("))
