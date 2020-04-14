#15998 카카오머니

#소수 구하기 , 약수구하기, 최대공약수 시간복잡도 최소 코드 외워두기

def GCD(a,b):
    while b!= 0:
        temp = a % b
        a = b
        b = temp
    return a

#유클리드 호제법
###############################



if __name__=="__main__":
    N = int(input())
    pair = [list(map(int, input().split())) for _ in range(N)]
    ans = 0
    MIN = pow(10,18)
    res = pow(10,18)

    for i in range(0,len(pair)):
        if pair[i][0] < 0: #출금이면
            res = GCD(res,pair[i][1] - pair[i-1][1] - pair[i][0]) 

    for i in range(0,N):
        if pair[i][0] >= 0: #입금
            if i == 0: #첫번째는 단순비교
                if pair[i][0] != pair[i][1]: #첫번째 입금과 현재금액이 다르면
                    ans = -1
                    break
                else: continue
            else:
                if pair[i-1][1] + pair[i][0] != pair[i][1]:
                    ans = -1
                    break
                else: continue

        else : #출금
            if i == 0:
                if pair[i][1] != 0: #현재 돈이 없는데 출금했으니깐 0이어야함.
                    ans = -1
                    break
            '''if pair[i][0] + pair[i-1][1] > 0:
                ans = -1
                break'''
            else:   
                if pair[i-1][1] >= abs(pair[i][0]): #남는 돈으로 출금가능
                    if pair[i-1][1] + pair[i][0] != pair[i][1]:
                        ans = -1
                        break
                    else: continue
                else: #남는 돈으로 출금 불가능 -> 통장에서 돈 빼와야함
                    if pair[i][1] >= res:
                        ans = -1
                        break
    if ans == -1:
        print(ans)            
    else: print(res)