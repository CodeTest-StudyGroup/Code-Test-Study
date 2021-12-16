import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = [[0] * (m + 1)]

for _ in range(n):
    a = [0] + list(map(int, input().rstrip()))
    arr.append(a)
max_square = 0

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if arr[i][j] == 0:
            continue
        arr[i][j] += min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1])
    max_square = max(max_square, max(arr[i]))
print(max_square ** 2)