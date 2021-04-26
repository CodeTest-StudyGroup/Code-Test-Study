"""
백준 벽 부수고 이동하기4
https://www.acmicpc.net/problem/16946

INPUT
3 3
101
010
101

OUTPUT
303
050
303

"""

import copy

dx = [1,-1,0,0]
dy = [0,0,1,-1]
def fill_zero(zero_point, cur_v):
    result = 0
    queue = [zero_point]
    while queue:
        x,y = queue.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 < nx <= N and 0 < ny <= M:
                if vmat[nx][ny] == 0 :
                    queue.append([nx,ny])
                    vmat[nx][ny] = cur_v
                    result += 1
    return result

def bfs(cur_v):
    result = 0
    v_list = []
    x,y = cur_v
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 < nx <= N and 0 < ny <= M:
            if vmat[nx][ny] > 1 and vmat[nx][ny] not in v_list:
                # print(x,y,nx,ny, vmat[nx][ny])
                result += sum_dict[vmat[nx][ny]]
                v_list.append(vmat[nx][ny])
    return result

N,M = list(map(int, input().split()))
mat = [[0] * (M+1) for _ in range(N+1)]

zero_list = []
one_list = []
for i in range(1,N+1):
    mat[i] = [0] + list(map(int, list(input())))
    for j in range(1,M+1):
        if mat[i][j] == 0:
            zero_list.append([i,j])
        else:
            one_list.append([i,j])
# print(zero_list)

vmat = copy.deepcopy(mat)

cnt = 2
sum_dict = dict()
for zl in zero_list:
    x,y = zl
    if vmat[x][y] == 0:
        vmat[x][y] = cnt
        sum_dict[cnt] = 1
        sum_v = fill_zero([x,y], cnt)
        sum_dict[cnt] += sum_v
        cnt += 1

# print(sum_dict)
# for i in vmat:
#     print(i)


for ol in one_list:
    x,y = ol
    result = bfs([x,y])
    mat[x][y] = (result + 1) % 10


for i in range(1,N+1):
    for j in range(1,M+1):
        print(mat[i][j],end='')
    print()

