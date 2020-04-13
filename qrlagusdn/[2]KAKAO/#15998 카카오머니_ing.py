#15998 카카오머니
def GCD2Num(a,b):
    while b!= 0:
        temp = a
        a = b
        b = a%b
    return a

def GCD(arr):
    gcd = arr[0]
    for i in range(1,len(arr)):
        gcd = GCD2Num(gcd,arr[i])
    return gcd
#유클리드 호제법
###############################

def getGCD(value,size):
    MIN = pow(10,18)
    gcd = -1
    for i in range(0,len(value)):
        MIN = min(MIN, value[i])
    
    for i in range(2,MIN+1):
        cnt = 0
        for j in range(0,len(value)):
            if value[j] % i == 0: #나누어떨어지면
                cnt += 1
        if cnt == size:
            gcd = i
    return gcd


if __name__=="__main__":
    N = int(input())
    pair = list()
    for _ in range(N):
        arr = list(map(int,input().split()))
        pair.append(arr)
    value = list()
    for i in range(0,len(pair)):
        if pair[i][0] < 0: #출금이면
            if pair[i-1][1] + pair[i][0] < 0:#현재 돈이 충분하지않음
                value.append(pair[i][1] - pair[i-1][1] - pair[i][0]) #value =n*m
                #bi -  b(i-1) - ai
                #bi < m
    #value들의 최대공약수 구하기
    #gcd = getGCD(value,len(value))
    gcd = GCD(value)

    if gcd != -1: #최대공약수가 있다
        if pair[0][0] != pair[0][1]:
            gcd = -1
        else:
            for i in range(1,len(pair)):
                a2 = pair[i][0]
                b2 = pair[i][1]
                b1 = pair[i-1][1]

                if b2 - b1 == a2:
                    continue
                
                if gcd <= b2 or (b2 - b1 - a2) % gcd != 0:
                    gcd = -1
                    break

                '''if abs(a2) % gcd == 0: #나누어떨어지면
                    if b1 == b2: continue
                    #이전 남는 값과 현재 남는 값이 일치

                    else: 
                        gcd = -1
                        break
                else:#나누어 떨어지지 않으면
                    if ((b1 + a2) // gcd + 1) * gcd + (b1 + a2) == b2:
                        continue
                    else:
                        gcd = -1
                        break'''
    print(gcd)