n = int(input())

num = list(map(int, input().split()))

plus_cnt = 0
div_max = 0

for i in num:
    div = 0
    while i > 0:
        if i % 2 == 0:
            i //= 2
            div += 1
        else:
            i -= 1
            plus_cnt += 1
    div_max = max(div_max, div)
print(plus_cnt + div_max)  