#2020카카오 괄호변환

'''
문제를 차근차근 똑바로 읽자
'''

from collections import Counter

def check(val):#올바른 괄호문자열 체크
    stack = list()
    for i in range(0,len(val)):
        if val[i] == '(':
            stack.append(val[i])
        else:
            if not stack: 
                return False
            stack.pop()
    if stack:
        return False
    return True

def u_check(u):
    #단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 한다
    for i in range(len(u)-1,0,-1):
        u1 = u[:i]
        u2 = u[i:]
        #u가 균형잡힌 문자열로 나누어질 수 있다면
        if u1.count('(') == u1.count(')') and u2.count('(') == u2.count(')'):
            return 1
    return 0

def recur(p):
    if p == '':
        return ''

    for i in range(1, len(p)+1):
        u = p[:i]
        v = p[i:]
        if u.count('(') == u.count(')') and u_check(u) == 0: #u가 균형잡힌 문자열이어야함
            if check(u):#u가 올바른 괄호문자열이면
                u += recur(v)
                return u
            else:
                #u의 앞뒤 제거
                u = u[1:] 
                u = u[:len(u)-1]
                #u 나머지 문자 뒤집기
                tmp = [u[i] for i in range(0,len(u))]
                for j in range(0,len(u)):
                    if u[j] == ')': 
                        tmp[j] = '('
                    elif u[j] == '(': 
                        tmp[j] = ')'
                tmp = ''.join(tmp)
                #더해주기
                val = '(' + recur(v) + ')' + tmp
                return val



def solution(p):
    answer = ''
    if p != '': #빈문자열이 아닌경우
        answer = recur(p)
    return answer

if __name__ == "__main__":
    print(solution("()"))