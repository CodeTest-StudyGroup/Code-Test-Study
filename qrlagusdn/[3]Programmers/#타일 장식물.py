#타일 장식물
def solution(N):
    answer = 0
    arr = [0] * 82
    dp = [0] * (N+1)
    arr[1] = 1
    arr[2] = 1
    dp[1] = 2
    for i in range(3,81):
        arr[i] = arr[i-2]+arr[i-1]
    for i in range(2,N+1):
        dp[i] = dp[i-1] + arr[i]
    
    answer = dp[N] *2
    return answer