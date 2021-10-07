n = int(input())

ans = [[] for _ in range(7)]

def div(l, r, cnt):  
    if cnt == 7:
        return    
    
    mid = (l + r) // 2

    for i in range(l, mid):
        ans[cnt] += "A"
    
    for j in range(mid, r):
        ans[cnt] += "B"

    div(l, mid, cnt + 1)
    div(mid, r, cnt + 1)

div(0, n, 0)

rest = ""
rest_ans = ""

for i in range(n):
    rest += "B"
    if i == 0:
        rest_ans += "A"
    else:
        rest_ans += "B"

for i in range(7):
    if "".join(ans[i]) == rest:
        print(rest_ans)
    else:
        print("".join(ans[i]))