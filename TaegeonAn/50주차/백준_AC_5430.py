# 1) R이면 flag *= -1 
# 2) D이면 flag가 플러스면 앞에서부터 pop, 마이너스면 뒤어서부터 pop
# 3) 반복문 다 수행 후 flag가 0 이하라면 배열이 뒤집힌다는 소리니까 뒤집어서 출력

from collections import deque

T = int(input())
for _ in range(T):
    answer = ""
    func = list(input())
    n = int(input())
    arr = input()
    arr = arr[1:-1].split(',')
    
    arr = deque(arr)
    if n == 0:
        arr = []
    case = 1
    flag = 1
    for f in func:
        if f == "R":
            flag *= -1
            
        else:
            if len(arr) <= 0:
                case = -1
                break

            if flag > 0:
                arr.popleft()
            else:
                arr.pop()

    if case != -1:
        if flag < 0:
            arr = list(arr)[::-1]
        answer = "[" + ','.join(arr) + "]"
    else:
        answer = "error"

    print(answer)