string = list(input().rstrip())
bomb = list(input())
stack = []

for char in range(len(string)):
    stack.append(string[char])
    
    if ''.join(stack[-len(bomb):]) == ''.join(bomb):
        del stack[-len(bomb):]
        
result = ''.join(stack)

if len(stack) > 0:
    print(result)
else:
    print("FRULA")