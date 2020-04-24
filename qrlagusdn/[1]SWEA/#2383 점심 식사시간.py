#2383 swea 점심 식사시간

'''
바보같이 순열이랑 조합만 계속 쓰면서 중복이 왜 안되냐고, 왜 실행안되냐고 10분20분을 헤매고 있었다.... ㅋㅋㅋㅋㅋㅋㅋㅋ 하ㅏ하하하ㅏㅎ..

'''

from itertools import product,combinations
from collections import deque

if __name__ == "__main__":
    T = int(input())
    for TC in range(1,T+1):
        N = int(input())
        MAP = [list(map(int,input().split()))for _ in range(N)]
        stair = list()
        people = [] #[사람idx,1번계단과의 거리, 2번과의 거리...]
        for i in range(0,N):#계단 추가
            for j in range(0,N):
                if MAP[i][j] > 1:
                    stair.append((i,j,MAP[i][j]))
        for i in range(0,N):#사람정보 추가
            for j in range(0,N):
                if MAP[i][j] == 1:
                    distance = list()
                    for s in stair:
                        distance.append(abs(i-s[0]) + abs(j-s[1]))
                    people.append(distance)

        stair_idx = [i for i in range(0,len(stair))]
        MIN = 9999999999


        for val in product(stair_idx,repeat = len(people)):
            distance = [0]*len(people)
            for i in range(0,len(people)):
                for j in range(0,len(stair)):
                    if val[i] == j:
                        distance[i] = people[i][j]#j 계단과의 거리
            #여기까지 하면 중복조합에 맞는 계단과의 거리가 distance에 나옴!
            
            time = 0
            on_stair = [[-1,-1,-1] for _ in range(len(stair))]
            wait_queue = list()
            visited = [0]*len(people)
            while 1:
                if sum(distance) == -(len(people)) and not wait_queue and (0 not in visited):
                    flag = 0
                    for s in on_stair:
                        for ss in s:
                            if ss != -1:
                                flag = 1
                                break
                    if flag == 0:#모두 계단에서 내려왔다면
                        #계단에 도착한것말고 내려온지도 확인해야함
                        #미니멈 체크하고
                        MIN = min(time,MIN)
                        break

                if time >= MIN: break

                for i in range(0,len(distance)):
                    if distance[i] == -1 and visited[i] == 0:#계단에 도착!
                        #val[i]는 계단의 idx를 의미함!
                        if on_stair[val[i]][0] == -1 or on_stair[val[i]][1] == -1 or on_stair[val[i]][2] == -1:
                            #계단에 3명 미만이 있다면
                            idx = on_stair[val[i]].index(-1)
                            on_stair[val[i]][idx] = stair[val[i]][2]#1명올린다. 계단의 크기만큼 올림!
                            visited[i] = 1
                        else:
                            #wait queue 만들기
                            #들어가야 할 계단위치 넣기
                            wait_queue.append(val[i]) #가야할 계단 idx
                            visited[i] = 1
                    elif distance[i] >= 0:
                        distance[i] -= 1

                #시간마다 on_stair 값 줄여주면서, 만약에 0이되면 pop하기
                for i in range(0,len(on_stair)):
                    for j in range(0,3):
                        if on_stair[i][j]>0:
                            on_stair[i][j] -= 1
                            if on_stair[i][j] == 0:
                                on_stair[i][j] = -1 #비었다는 표시
                                if i in wait_queue:#기다리는 큐에 빈 계단에 가야할 사람이 기다리고 있으면
                                    on_stair[i][j] = stair[val[i]][2]
                                    wait_queue.pop(wait_queue.index(i))               
                    
                #시간 증가
                time += 1
        print("#%d %d" %(TC,MIN))


'''
1
5
0 0 1 1 0
0 0 1 0 2
0 0 0 1 0
0 1 0 0 0
1 0 5 0 0
'''