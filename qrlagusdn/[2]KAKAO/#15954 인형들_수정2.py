#15954 인형들
#범위 조정때문에 살짝 고민했음
#싹 다 돌았음
#?? 3차 포문 안돌아가는데
#min append 한다고 바뀌는건 없음
#fastinput 차이가 클까?

#다른사람 3중포문쓰니깐 돌아가네...
#fastinput은 상관이없다.
#tmp 문제도 아니다.

#,,,,,,,,,, 결국 그냥 비교문 하나 차이때문에 시간초과...
# fastinput도, tmp도, for문 조건식 차이도 아니다....
#ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ

import sys
import math
import decimal

def doll(): #start ~ idx -1 까지
    MIN=99999
    MINlist = list()
    for i in range(0,N-K+1):
        for j in range(i+K, N+1):
            m = (sum(arr[i:j])) / (j - i)
            var = 0
            for t in range(i, j):
                var += (arr[t] - m)**2
                
            dev = (var) / (j -i)
            MINlist.append(dev)
            #MIN = min(MIN,dev)
            #원래는 계속 다 비교했었는데 시간초과
    '''for i in range(N-K+1):
        for j in range(N-K-i+2):
            tmp = arr[i:i + K + j]
            m = sum(tmp) / len(tmp)
            result = 0
            for t in tmp:
                result += (t-m)**2
            MINlist.append(result/len(tmp))'''
    return min(MINlist)

if __name__ == "__main__":
    N, K = map(int,input().split())
    arr = list(map(int,input().split()))
    MIN = doll()
    print(math.sqrt(MIN))