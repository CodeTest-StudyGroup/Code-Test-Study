from itertools import combinations
from collections import Counter


def solution(clothes):
    sum = 1
    visited = []
    for cloth in clothes:
        flag = 0
        if cloth[1] in visited: continue
        visited.append(cloth[1])
        for cloth2 in clothes:
            if cloth2[1] == cloth[1]:
                flag += 1
        print(flag)
        sum *= (flag+1)
    answer = sum -1
    return answer



'''
길이 i로 잡고 combinations 해서 비교한다음에 실행시키니깐 시간초과

길이 1~len(clothes) 잡고 dfs 돌려도 옷의 최대수가 30개라서 조합 
돌리니깐 시간초과 발생....
알고리즘을 조금 참고해서 풀어야했다...

answer = 0
def dfs(idx,visited,cnt,clothes,start):
    global answer
    if cnt >= idx:
        answer += 1
        return
    
    for i in range(start,len(clothes)):
        if clothes[i][1] not in visited:
            visited.append(clothes[i][1])
            dfs(idx,visited,cnt+1,clothes,i+1)
            visited.pop()
            

def solution(clothes):
    for i in range(1,len(clothes)+1):
        visited = []
        dfs(i,visited,0,clothes,0)
    return answer

    '''