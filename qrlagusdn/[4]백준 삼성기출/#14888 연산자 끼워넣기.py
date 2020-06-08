#14888 연산자 끼워넣기
#주어진 숫자까지 순서가 바뀔수있는줄 알고 permutation 2번 사용해서 열심히 했드만, 아니었다... 연산자만 순서 이동가능함!

#근데 이렇게 순열 사용해서 쫙 했는데 시간이 엄청 오래걸린다. 왠지 시간초과 뜰 것 같은느낌....
from itertools import permutations

MIN = 1000000001
MAX = -1000000001

def cal(arr,op):
    global MIN
    global MAX
    sum =arr[0]
    for i in range(0,len(arr)-1):
        if op[i] == 0:#plus
            sum += arr[i+1]
        elif op[i] == 1:#sub
            sum -= arr[i+1]
        elif op[i] == 2:#mul
            sum *= arr[i+1]
        elif op[i] == 3:#div
            if sum < 0:
                sum = abs(sum)//arr[i+1]
                sum = -sum
            else:
                sum //= arr[i+1]
    MAX = max(MAX,sum)
    MIN = min(MIN,sum)


N = int(input())
arr = list(map(int,input().split()))
op = list(map(int,input().split()))
op_list = list()
for i in range(4):
    for j in range(op[i]):
        op_list.append(i)
op_val = list(permutations(op_list,N-1))


for i in range(len(op_val)):
    cal(arr,op_val[i])
print(MAX)
print(MIN)