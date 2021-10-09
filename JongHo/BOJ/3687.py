import sys
input = sys.stdin.readline

number = [2, 5, 5, 4, 5, 6, 3, 7, 6, 6]

T = int(input())

res = [[10**26, ""] for _ in range(101)]
res[2] = ["1", "1"]
res[3] = ["7", "7"]
res[4] = ["4", "11"]
res[5] = ["2", "71"]
res[6] = ["6", "111"]
res[7] = ["8", "711"]

for i in range(8, 101):
        for j in range(2, i//2 + 1):
            mini = list(res[j][0] + res[i - j][0])
            mini.sort()
            # 맨 앞이 0이면 0이 아닌 가장 작은 수와 교환한다.
            if mini[0] == "0":
                for h in range(1, len(mini) - 1):
                    if mini[h] != "0":
                        mini[0], mini[h] = mini[h], mini[0]
                        break          
            mini = "".join(mini)
            # 맨 앞을 제외한 나머지 자리에 6을 전부 0으로 바꾼다.
            mini = mini[0] + mini[1:].replace("6", "0")
            res[i][0] = str(min(int(res[i][0]), int(mini)))
        # 최댓값은 i-2개로 했을때 최댓값에 1을 계속 추가해 준다.(문자열)
        res[i][1] = res[i - 2][1] + res[2][1]

for n in range(T):
    n = int(input())
    
    print(res[n][0], res[n][1])