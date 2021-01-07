s=input();stack=[];answer=''
for c in s:
    if ord('A')<=ord(c)<=ord('Z'): answer+=c
    elif c=='*' or c=='/' or c=='(': 
        if c=='(': stack.append(c)
        else:
            while stack:
                if stack[-1]=='*' or stack[-1]=='/': answer+=stack.pop()
                else: break
            stack.append(c)
    elif c=='+' or c=='-': 
        while stack:
            if stack[-1]=='+' or stack[-1]=='-' or stack[-1]=='*' or stack[-1]=='/': answer+=stack.pop()
            else: break
        stack.append(c)
    elif c==')':
        while stack[-1]!='(': answer+=stack.pop()
        stack.pop()
while stack:
    answer+=stack.pop()
print(answer)