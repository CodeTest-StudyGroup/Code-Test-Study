import sys
import math


def deviation(arr, value):  # 표준 편차
    result = 0
    for i in range(len(arr)):
        result += abs(pow(arr[i] - value, 2))

    return math.sqrt(result / len(arr))


if __name__ == "__main__":

    N, K = map(int, input().split())
    data = list(map(int, input().split()))

    if K == 0:
        print(0)
    else:
        min_deviation = sys.maxsize
        for k in range(N, K - 1, -1):  # [N ~ K]
            for j in range(0, N - k + 1):
                temp = data[j:j + k]
                temp_deviation = deviation(temp, sum(temp) / len(temp))

                min_deviation = min(min_deviation, temp_deviation
        print(min_deviation)
