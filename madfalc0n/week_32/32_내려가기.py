"""
내려가기
https://www.acmicpc.net/problem/2096

"""

def dp(input_list, sw):
    tmp_list = [0] * 3
    if sw: # max   
        tmp_list[0] = input_list[0] + max(max_list[0], max_list[1])
        tmp_list[2] = input_list[2] + max(max_list[1], max_list[2])
        tmp_list[1] = input_list[1] + max(max_list[0], max_list[1], max_list[2])
        return tmp_list

    else:
        tmp_list[0] = input_list[0] + min(min_list[0], min_list[1])
        tmp_list[2] = input_list[2] + min(min_list[1], min_list[2])
        tmp_list[1] = input_list[1] + min(min_list[0], min_list[1], min_list[2])
        return tmp_list

n = int(input())
# m = []
max_list = [0] * 3
min_list = [0] * 3
for i in range(n):
    input_list = list(map(int, input().split(' ')))
    max_list = dp(input_list, 1)
    min_list = dp(input_list, 0)

print(max(max_list), min(min_list))

