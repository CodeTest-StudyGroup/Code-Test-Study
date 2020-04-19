#2382 swea 미생물 격리

#겹치는 부분 관리하는 것 생각보다 시간이 많이걸림
#리스트에서 set을 쓰고 싶었는데 튜플이라서 못썼고, 2중포문으로 관리를 해야하는데 겹치는 부분 체크하고 넘어가는 것을 visited로 안하고 이상하게 접근해서 계속 오답 나온듯!

import copy

dy = [0,-1,1,0,0] #0, 상하좌우
dx = [0,0,0,-1,1] #0, 상하좌우

if __name__ == "__main__":
    T = int(input())

    for TC in range(1,T+1):
        N,M,K = map(int,input().split())
        MAP = [list(map(int,input().split())) for _ in range(K)]
        #세로위치, 가로위치, 미생물 수, 이동방향

        while M:
            MAP2 = list()
            MAP3 = list()
            for i in range(0,len(MAP)): #움직이기
                newy = MAP[i][0]+dy[MAP[i][3]]
                newx = MAP[i][1]+dx[MAP[i][3]]
                if newx==0 or newx==N-1 or newy==0 or newy==N-1: #약품위치에 오면
                    amount = MAP[i][2] // 2 #절반 죽임
                    if MAP[i][3] in [1,3]:#방향전환 1,3 -> +1  2,4 -> -1
                        dir = MAP[i][3] + 1
                    else:
                        dir = MAP[i][3] - 1
                else:
                    amount = MAP[i][2]
                    dir = MAP[i][3]

                MAP2.append((newy,newx,amount,dir))#위치 업데이트

            #한번 쭉 돌면서 겹치는 부분 체크해주기
            visited = [[0 for _ in range(N)]for _ in range(N)]
            for i in range(0,len(MAP2)):#위치가 같다면 업데이트
                y = MAP2[i][0]
                x = MAP2[i][1]
                if visited[y][x] == 1:
                    continue
                visited[y][x] = 1

                amount = MAP2[i][2]
                max_amount = MAP2[i][2]
                dir = MAP2[i][3]
                for j in range(i+1,len(MAP2)):
                    if y == MAP2[j][0] and x == MAP2[j][1]:
                        amount += MAP2[j][2]
                        if max_amount < MAP2[j][2]:
                            dir = MAP2[j][3]
                            max_amount = MAP2[j][2]

                MAP3.append((y,x,amount,dir))

            MAP = copy.deepcopy(MAP3)
            M -= 1
        
        answer = 0
        for i in range(0,len(MAP)):
            answer += MAP[i][2]
        
        print("#%d %d" %(TC,answer))
'''1
7 2 9
1 1 7 1
2 1 7 1
5 1 5 4
3 2 8 4
4 3 14 1
3 4 3 3
1 5 8 2
3 5 100 1
5 5 1 1

1
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
'''