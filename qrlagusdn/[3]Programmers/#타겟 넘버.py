#타겟 넘버
#중복 순열 잘 보기

from itertools import product
cnt = 0
def cal(numbers,op,target):
    global cnt
    sum = 0
    for i in range(0,len(numbers)):
        if op[i] == 0: #+
            sum += numbers[i]
        elif op[i] == 1: #-
            sum -= numbers[i]
    if sum == target:
        cnt+=1

def solution(numbers, target):
    op = [0,1]
    for val in product(op,repeat = len(numbers)):
        #print(val)
        cal(numbers,val,target)
    
    print(cnt)
    return cnt


if __name__ == "__main__":
    arr = [1,1,1,1,1]
    num = 3
    solution(arr,num)