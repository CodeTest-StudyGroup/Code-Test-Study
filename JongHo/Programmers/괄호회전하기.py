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