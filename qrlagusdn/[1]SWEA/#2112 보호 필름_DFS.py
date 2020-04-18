#2112 보호 필름

#와,,, 이 문제도 순열조합 쓰면 아주 쉽게 풀릴듯,,,, 충격,,


import copy

answer = 9999999

def check(MAP):
    check_arr = [0 for _ in range(W)]

    for col in range(0,W):
        cnt = 0
        prev = -1
        for row in range(0,D):
            #if D-row < K: #남은 개수가 K보다 작다면 아웃
             #   break
            
            if prev == -1:
                prev = MAP[row][col]
                cnt =1
            elif prev == MAP[row][col]:
                cnt+=1
            elif prev != MAP[row][col]:
                prev = MAP[row][col]
                cnt = 1

            if cnt == K:
                check_arr[col] = 1
                break

        if check_arr[col] != 1: #해당 열이 안되면 어짜피 안되니깐 아웃!
            break

    if 0 in check_arr:
        return 0
    else:
        return 1

def dfs(visited,MAP,cnt):
    global answer
    if cnt > K: 
        return

    if check(MAP):
        if answer > cnt:
            answer = cnt
        return

    if cnt >= answer:
        return
    

    for i in range(0,D):
        if visited[i] == 0: #약품 투여 위치 i-row
            visited[i] = 1
            MAP2 = copy.deepcopy(MAP)
            for j in range(0,W): #A로 약품투여
                MAP2[i][j] = 0
            dfs(visited,MAP2,cnt+1)
            MAP2 = copy.deepcopy(MAP)

            for j in range(0,W): #B로 약품투여
                MAP2[i][j] = 1
            dfs(visited,MAP2,cnt+1)
            MAP2 = copy.deepcopy(MAP)
            visited[i] = 0



if __name__ == "__main__":
    T = int(input())

    for TC in range(1,T+1):
        D,W,K = map(int,input().split())
        MAP = [list(map(int,input().split())) for _ in range(D)]
        visited = [0 for _ in range(D)]
        answer = 9999999

        if K == 1:
            print("#%d %d" %(TC,0))
        else:
            dfs(visited,MAP,0)
            print("#%d %d" %(TC,answer))
'''
1           
6 8 3         
0 0 1 0 1 0 0 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1

1
6 8 3         
1 1 1 1 0 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 0 0 1 0
1 1 1 0 0 1 1 0
1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0

1
6 8 4
1 1 0 0 0 1 1 0
1 0 1 0 0 1 1 1
0 1 0 0 1 1 0 0
1 0 1 0 0 0 0 0
1 1 0 0 0 0 0 0
1 0 0 0 1 1 1 1
'''