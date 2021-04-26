"""
회전 초밥
https://www.acmicpc.net/problem/15961

"""

n,d,k,c = list(map(int, input().split(' ')))
# print(n,d,k,c)

sushi = []
val_set = ()
for i in range(n):
    sushi.append(int(input()))

sushi_dict = dict.fromkeys(set(sushi),0)
sushi_dict[c] = 0
# print(sushi_dict)

result = 0
max_val = 0
for i in range(k):
    val = sushi[i]
    if sushi_dict[val] == 0:
        max_val += 1
    sushi_dict[val] += 1

if sushi_dict[c] == 0:
    result = max_val + 1
else:
    result = max_val


sushi += sushi[:k]
# print(sushi)
# print(max_val)
# print(sushi_dict)


for i in range(1,n):
    old, _, end = sushi[i-1], sushi[i], sushi[i+k-1]
    
    sushi_dict[old] -= 1
    if sushi_dict[old] == 0:
        max_val -= 1
    
    sushi_dict[end] += 1
    if sushi_dict[end] == 1:
        max_val += 1
    
    if sushi_dict[c] == 0:
        result = max(max_val + 1, result)
    else:
        result = max(max_val , result)
    
    if result == k + 1:
        break
    # print(end)
    # print(sushi_dict, result)

print(result)