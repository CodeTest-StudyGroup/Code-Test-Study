def check(g):
    stack = []
    for i in range(len(g)-1, -1, -1):
        if not stack:
            stack.append(g[i])
            continue
            
        if g[i] + stack[-1] == "()":
            stack.pop()
        elif g[i] + stack[-1] == "{}":
            stack.pop()
        elif g[i] + stack[-1] == "[]":
            stack.pop()
        else:
            stack.append(g[i])
            
    if stack:
        return False
    return True
                
        

def solution(s):
    s = list(s)
    answer = 0
    for _ in range(len(s)):
        if check(s):
            answer += 1
        span = s.pop(0)
        s.append(span)
    
    return answer

# 괄호들로 구성된 문자열을 받는다.
# 왼쪽으로 한 칸씩 회전마다 괄호체크를 해준다.
# 짝이 맞으면 answer에 1을 더해준다.
# 이렇게 한 바퀴를 돌고 나서 짝이 맞았던 경우의 수를 출력한다.