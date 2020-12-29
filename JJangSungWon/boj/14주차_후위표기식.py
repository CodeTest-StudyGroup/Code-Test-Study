from collections import deque


if __name__ == "__main__":
    infix = list(map(str, input().strip()))

    s = []
    postfix = ""

    for i in range(len(infix)):
        if 'A' <= infix[i] <= 'Z':  # 연산자가 아니면 postfix 에 더합니다.
            postfix += infix[i]
        else:
            if infix[i] == ')':
                while len(s) != 0 and s[-1] != '(':
                    postfix += s.pop()
                s.pop()
            elif infix[i] == '+' or infix[i] == '-':
                while len(s) != 0 and s[-1] != '(':
                    postfix += s.pop()
                s.append(infix[i])
            elif infix[i] == '*' or infix[i] == '/':
                while len(s) != 0 and (s[-1] == '*' or s[-1] == '/'):
                    postfix += s.pop()
                s.append(infix[i])
            elif infix[i] == '(':
                s.append(infix[i])

    while len(s) != 0:
        postfix += s.pop()

    print(postfix)