def solution(land):
    dp = [[0] * 4 for _ in range(len(land))]
    for i in range(4):
        dp[0][i] = land[0][i]

    for i in range(1, len(land)):
        for j in range(4):
            if j == 0:
                dp[i][j] = land[i][j] + max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3])
            elif j == 1:
                dp[i][j] = land[i][j] + max(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3])
            elif j == 2:
                dp[i][j] = land[i][j] + max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][3])
            else:
                dp[i][j] = land[i][j] + max(dp[i- 1][0], dp[i - 1][1], dp[i - 1][2])
    return max(dp[len(land) - 1][0], dp[len(land) - 1][1], dp[len(land) - 1][2], dp[len(land) - 1][3])


if __name__ == "__main__":
    print(solution([[1, 2, 3, 5], [5, 6, 7, 8], [4, 3, 2, 1]]))


"""
1 2 3 5
5 6 7 8
4 3 2 1
"""