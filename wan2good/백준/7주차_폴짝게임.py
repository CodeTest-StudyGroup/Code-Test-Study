n,m,d = map(int,input().rstrip().split())
board = []
for _ in range(n):
    board.append(list(map(int,input().rstrip().split())))

INF = 2e10
dp = [[-INF] * m for _ in range(n)]
for i in range(m):
    dp[0][i] = 0

for i in range(n):
    for j in range(m):
        for x in range(i+1,i+d+1):
            for y in range(j-d+1,j+d):
                if 0<=x<n and 0<=y<m and abs(x-i)+abs(y-j)<=d:
                    dp[x][y] = max(dp[x][y], dp[i][j] + board[i][j]*board[x][y])


maxValue = -INF
for value in dp[n-1]:
    maxValue = max(maxValue,value)

print(maxValue)