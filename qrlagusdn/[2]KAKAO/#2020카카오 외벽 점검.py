#2020카카오 외벽 점검
'''
circular 의 특성을 사용하면 시계 반시계 따로 고려할 필요 없다?


permutation 돌리는게 맞는데 시간초과가 발생한다. ㅜㅜ

'''

import copy
from itertools import combinations,permutations


MIN = 99999999
def check(visited,weak,dist,start):
    global MIN
    if sum(weak) == len(weak)*(-1): #모두 다 돌았다면
        MIN = min(MIN,visited.count(1))
        return
    
    if sum(visited) >= MIN:
        return

    for i in range(0,len(dist)):
        if visited[i] == 0:
            
            tmp = copy.deepcopy(weak)
            limit = tmp[start]+dist[i]
            tmp[start] = -1
            cnt = 1
            for j in range(start+1,len(tmp)):
                if tmp[j] <= limit:
                    tmp[j] = -1
                    cnt += 1
                else:
                    break
                
            visited[i] = 1
            check(visited,tmp,dist,start+cnt)
            tmp = copy.deepcopy(weak)
            visited[i] = 0
    

def solution(n, weak, dist):
    answer = 0
    global MIN
    tmp_arr = []
    for i in range(len(weak)): # 1 5 6 10, 5 6 10 13, 6 10 13 17, 10 13 17 18 로 가능한 값 다 만들기
        tmp = copy.deepcopy(weak)
        for _ in range(i):
            tmp.append(tmp.pop(0)+n)
        tmp_arr.append(tmp)

    
    for l in range(1,len(dist)+1): # 1명부터 모두다 참여까지
        if MIN <= l: #최소값보다 참여하는 친구의 수가 많으면 그만
            break
        
        for val in permutations(dist,l):#tmp, val #참여하는 친구 순열 만들기
            print(val)
            if MIN <= l:
                break
            for tmp_weak in tmp_arr:
                tmp2 = copy.deepcopy(tmp_weak)
                idx = 0
                for v in val: #친구 한명씩 맨 앞에서부터 weak을 채워나간다.
                    limit = tmp2[idx]+v #갈수 있는 최대값은 시작점에서 친구 값 더한 값.
                    tmp2[idx] = -1 #시작점을 -1로 두고
                    idx += 1 #idx를 늘려간다.
                    while 1:
                        if idx>= len(tmp2):break #만약 인덱스 값이 weak을 넘어가면 그만
                        if tmp2[idx] <= limit: #만약 weak의 idx 값이 limit보다 아래면 -1로 표시해준다
                            tmp2[idx] = -1
                        else: #그게 아니면 그만 
                            break
                        idx += 1
                if sum(tmp2) == len(tmp2)*(-1): #만약 다 방문했다면 min 체크해주기
                    MIN = min(MIN,l)
                    
    if MIN>len(dist):
        answer = -1
    else:
        answer = MIN
    return answer

if __name__ == "__main__":
    print(solution( 50, [1, 5, 10, 12, 22, 25], [4, 3, 2, 1]))