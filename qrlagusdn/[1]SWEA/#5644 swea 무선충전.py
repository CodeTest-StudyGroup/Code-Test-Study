#5644 swea 무선충전

'''
범위를 dfs로 지정해주려고 했는데 계속 막히더라. 그래서 그냥 이중포문으로 체크할 예정
마름모와 같은 것은 BFS로 하려하니깐 cnt를 어떻게 세어줘야하는지 모르겠고, dfs로 하니깐 다음 깊이에서 상하좌우 다 돌아버리니깐 그 이전 깊이로 왔을때 막혀버린다.
10x10 이니깐 충전기 개수만큼 100번 돌아도 그렇게 크지 않아서 괜찮을듯

https://yabmoons.tistory.com/221


하..'

요새 머리가 잘 안돌아간다.
상당히 어려웠다.

진짜 딱 저 로직만 파악한다면 구현이 어려운 것은 아닌데, 너무 꼬으고 꼬아서 생각했나보다...
나중에 다시 풀어보자!

*마름모와 같은 경우는 dfs로 구현이 힘들다.. Bfs도 어려운듯?? 한번 생각해보자

시뮬레이션 문제인데, 움직이는 사람이 2명이라는 것을 기억하자!
'''

dy = [0,-1,0,1,0]#x,상우하좌
dx = [0,0,1,0,-1]

if __name__ == "__main__":
    T = int(input())
    for TC in range(1,T+1):
        M,A = map(int,input().split())
        Aarr = list(map(int,input().split()))
        Barr = list(map(int,input().split()))
        BC = [list(map(int,input().split()))for _ in range(A)]
        #x,y,범위,처리량

        charge = [[[] for _ in range(10)] for _ in range(10)]
        idx=0
        for bc in BC: #충전 범위 지정
            y = bc[1] - 1
            x = bc[0] - 1
            for j in range(0,10):
                for i in range(0,10):
                    dis = abs(y-j)+abs(x-i)
                    if dis <= bc[2]:
                        charge[j][i].append(idx)
            idx += 1
        
        pos_A = [0,0] #y,x
        pos_B = [9,9]
        SUM = 0
        time = 0
        while 1:
            #A에 0개
            #B 0,1,2~
            
            #B에 0개
            #A 0,1,2~
            if len(charge[pos_A[0]][pos_A[1]]) >= 1 and len(charge[pos_B[0]][pos_B[1]]) >= 1: #둘다 1개 이상
                bigger = 0
                for A_charge in charge[pos_A[0]][pos_A[1]]:
                    for B_charge in charge[pos_B[0]][pos_B[1]]:
                        if A_charge == B_charge:
                            bigger = max(bigger, BC[A_charge][3])
                        else:
                            bigger = max(bigger, BC[A_charge][3] + BC[B_charge][3])
                SUM += bigger

            elif len(charge[pos_A[0]][pos_A[1]]) == 0:#A에 없음
                if len(charge[pos_B[0]][pos_B[1]]) == 1:
                    SUM += BC[charge[pos_B[0]][pos_B[1]][0]][3]
                elif len(charge[pos_B[0]][pos_B[1]]) > 1:
                    bigger = 0
                    for B_charge in charge[pos_B[0]][pos_B[1]]:
                        bigger = max(bigger,BC[B_charge][3])
                    SUM += bigger
                else:
                    pass

            elif len(charge[pos_B[0]][pos_B[1]]) == 0:#B에 없음
                if len(charge[pos_A[0]][pos_A[1]]) == 1:
                    SUM += BC[charge[pos_A[0]][pos_A[1]][0]][3]
                elif len(charge[pos_A[0]][pos_A[1]]) > 1:
                    bigger = 0
                    for A_charge in charge[pos_A[0]][pos_A[1]]:
                        bigger = max(bigger,BC[A_charge][3])
                    SUM += bigger
                else:
                    pass

            if time >= M:
                break
            pos_A = [pos_A[0]+dy[Aarr[time]],pos_A[1]+dx[Aarr[time]]]  
            pos_B = [pos_B[0]+dy[Barr[time]],pos_B[1]+dx[Barr[time]]] 
            
            time += 1
        print("#%d %d" %(TC,SUM))

###############################################################
            
            