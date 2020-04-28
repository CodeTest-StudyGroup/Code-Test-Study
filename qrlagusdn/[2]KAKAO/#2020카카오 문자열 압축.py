#2020카카오 문자열 압축

def solution(s):
    answer = 99999999999
    if len(s) == 1:
        return 1
    for i in range(1,len(s)):
        j = 0
        tmp = ""
        cnt = 0
        while 1:
            if j >=len(s):
                break
            if s[j:j+i] == s[j+i:j+2*i]:
                cnt += 1
            else:
                if cnt == 0:
                    tmp += s[j:j+i]
                else:
                    tmp += str(cnt+1) + s[j-i:j]
                    cnt = 0
            j = j+i
        answer = min(answer,len(tmp))

    return answer

if __name__ == "__main__":
    print(solution("a"))