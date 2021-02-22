import sys


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())

    # 누적합
    prefix_sum = [0] * n
    prefix_sum[0] = array[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i - 1] + array[i]

    dp = [[0 for _ in range(n)] for _ in range(3)]

    dp[0][m - 1] = prefix_sum[m - 1]
    for i in range(m, n):
        dp[0][i] = max(dp[0][i - 1], prefix_sum[i] - prefix_sum[i - m])

    dp[1][2 * m - 1] = prefix_sum[2 * m - 1]
    for i in range(2 * m, n):
        dp[1][i] = max(dp[1][i - 1], dp[0][i - m] + prefix_sum[i] - prefix_sum[i - m])

    dp[2][3 * m - 1] = prefix_sum[3 * m - 1]
    for i in range(3 * m, n):
        dp[2][i] = max(dp[2][i - 1], dp[1][i - m] + prefix_sum[i] - prefix_sum[i - m])

    print(dp[-1][-1])