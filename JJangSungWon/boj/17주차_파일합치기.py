import sys
import math


if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for _ in range(t):
        k = int(sys.stdin.readline())
        file = list(map(int, sys.stdin.readline().split()))

        # file 누적 합
        file_sum = {-1: 0}
        for i in range(len(file)):
            file_sum[i] = file_sum[i - 1] + file[i]

        # dp
        # do[i][j] -> i번 ~ j번 파일 합치는데 최소비용
        dp = [[0 for _ in range(len(file))] for _ in range(len(file))]
        # for i in range(k - 1):
        #    dp[i][i + 1] = file[i] + file[i + 1]
        for d in range(1, len(file)):
            for start in range(len(file)):
                end = start + d
                if end == k:
                    break
                dp[start][end] = math.inf
                for i in range(start, end):
                    dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + file_sum[end] - file_sum[start - 1])

        print(dp[0][-1])

