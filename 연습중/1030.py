s, n, k, r1, r2, c1, c2 = map(int, input().split())

def solution(r, c, s):
    if s == 0:
        return 0
    m = n ** (s - 1)
    black = (n - k) // 2
    if black * m <= r < (black + k) * m and black * m <= c < (black + k) * m:
        return 1
    r %= m
    c %= m
    return solution(r, c, s - 1)

answer = []
for i in range(r1, r2 + 1):
    li = [solution(i, j, s) for j in range(c1, c2 + 1)]
    answer.append(li)

for li in answer:
    print(''.join(map(str, li)))