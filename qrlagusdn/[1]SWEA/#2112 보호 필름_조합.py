#2112 보호 필름


import copy
from itertools import product

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



if __name__ == "__main__":
    T = int(input())

    for TC in range(1,T+1):
        D,W,K = map(int,input().split())
        MAP = [list(map(int,input().split())) for _ in range(D)]
        
        arr = [0,1,-1]
        answer = 999999
        if K == 1 or check(MAP): #k가 1이거나 맨첨부터 약물투여 안해도 되면 0 출력 후 아웃
            print("#%d %d" %(TC,0))
        else: #그게 아니면 모든 중복순열 만들어서 체크. -1은 안하는것 0은 A투여, 1은 B투여
            for val in product(arr,repeat=D):
                #print(val)
                MAP2 = copy.deepcopy(MAP)
                cnt = 0
                for row in range(0,D):
                    if val[row] == -1:
                        continue
                    
                    elif val[row] == 0:
                        cnt +=1
                        for col in range(0,W):
                            MAP2[row][col] = 0 #A 투여
                    elif val[row] ==1:
                        cnt +=1
                        for col in range(0,W):
                            MAP2[row][col] = 1 #B 투여
                    
                    if cnt>=answer:
                        break

                if cnt <= answer and check(MAP2):
                    answer = min(answer,cnt)
            print("#%d %d" %(TC,answer))

                


        '''if K == 1:
            print("#%d %d" %(TC,0))
        else:
            dfs(visited,MAP,0)
            print("#%d %d" %(TC,answer))'''
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