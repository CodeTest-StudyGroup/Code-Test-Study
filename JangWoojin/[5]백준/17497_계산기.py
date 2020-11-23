n = int(input())
cnt = 0
ans = ""
if n & 1:
    ans = "[/] " + ans
    n *= 2
    cnt += 1
while (n):
    if n & 2:
        ans = "[+] " + ans
        n -= 2
    else:
        ans = "[*] " + ans
        n //= 2
    cnt += 1
print(cnt, ans, sep='\n')
