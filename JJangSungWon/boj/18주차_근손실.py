import sys
from itertools import permutations


if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    array = list(map(int, sys.stdin.readline().split()))

    answer = 0
    for data in permutations(array, n):
        weight = 500
        flag = True
        for i in range(n):
            weight += data[i]  # 중량 증가
            weight -= k  # 중량 감소
            if weight < 500:  # 500 이상 확인
                flag = False
                break
        if flag:
            answer += 1

    print(answer)
