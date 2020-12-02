n = int(input())
alpha = [0 for _ in range(26)]
for _ in range(n):
    s = input()
    tmp = 10 ** (len(s) - 1)
    for c in s:
        alpha[ord(c) - ord('A')] += tmp
        tmp //= 10
alpha.sort(reverse=True)
ans, num = 0, 9
for i in range(9):
    ans += alpha[i] * num
    num -= 1
print(ans)
