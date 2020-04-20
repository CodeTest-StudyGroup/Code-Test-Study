#2117 swea 홈 방범 서비스

import copy

def check(y,x,K): #마름모 체크
    cnt=0
    for j in range(0,K):#K개 대각선 K번
        s_y = y-j
        s_x = x-K+1+j
        for i in range(0,K):
            s2_y = s_y+i
            s2_x = s_x+i
            if 0<=s2_y<N and 0<=s2_x<N and MAP[s2_y][s2_x] == 1:
                cnt+=1
    
    for j in range(0,K-1):#K-1개 대각선 K-1번
        s_y = y-j
        s_x = x-K+2+j
        for i in range(0,K-1):
            s2_y = s_y+i
            s2_x = s_x+i
            if 0<=s2_y<N and 0<=s2_x<N and MAP[s2_y][s2_x] == 1:
                cnt+=1
    return cnt

def solve():
    MAX = 0
    maxHouse = 0
    for y in range(0,N):
        for x in range(0,N):
            if N%2 == 0:#N이 짝수면
                P = N+1
            else:
                P = N
            for K in range(1,P+1):
                house = check(y,x,K)
                profit = house*M - (K*K+(K-1)*(K-1))
                if profit >=0: #손해보지않고
                    maxHouse = max(maxHouse, house)
    return maxHouse


if __name__ == "__main__":
    T = int(input())

    for TC in range(1,T+1):
        N,M = map(int,input().split())
        MAP = [list(map(int,input().split())) for _ in range(N)]
 
        answer = solve()
        print("#%d %d" %(TC,answer))
'''1
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0

1
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
'''