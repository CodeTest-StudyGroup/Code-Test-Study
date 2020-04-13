# boj 15998
# github blog : jjangsungwon.github.io
import sys


def gcd(a, b):
    while b != 0:
        temp = a % b
        a = b
        b = temp
    return a


if __name__ == "__main__":

    # input
    N = int(sys.stdin.readline())
    data = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    flag, money, min_account = True, 0, 0
    min_charge = sys.maxsize

    for i in range(N):
        if data[i][0] > 0:
            if data[i][0] + money != data[i][1]:
                flag = False
                break
        else:
            if data[i][0] + money > 0:
                if data[i][0] + money != data[i][1]:
                    flag = False
                    break
            else:
                sub_money = -data[i][0] + data[i][1] - money  # 필요한 금액

                # 잔돈 최솟값
                if data[i][1] != 0:
                    min_charge = min(data[i][1], min_charge)

                if min_account == 0:  # 처음에 바로 min_account 대입
                    min_account = sub_money
                else:
                    min_account = gcd(min_account, sub_money)
                    # 계좌에서 가져올 수 있는 최저금액보다 현재 금액이 클 수 없다. (data[i][0] + money < 0 이었기때문에)
                    if min_account <= min_charge != sys.maxsize:  # != pow(10, 18)을 안하면 65% 틀림
                        flag = False
                        break
        money = data[i][1]

    if flag and min_account == 0:  # 1이상 모든 값 가능한 상황
        print(1)
    elif flag and min_account != 0:
        print(min_account)
    else:  # 불가능 상황
        print(-1)
