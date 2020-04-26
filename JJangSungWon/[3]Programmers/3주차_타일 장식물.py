def solution(N):
    if N <= 2:
        return 1
    else:
        dp = [0] * (N + 1)
        dp[0], dp[1] = 1, 1

        for i in range(2, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        print(dp)
        answer = dp[N] * 2 + dp[N-1] * 2
        return answer


if __name__ == "__main__":
    print(solution(5))
