#숫자야구

from itertools import combinations,permutations

'''
base = [0,1,2]

def dfs(idx, answer,baseball):
    if idx >= len(baseball):
        return

    #for i in range(idx,len(baseball)):#질문의 수만큼

    if baseball[idx][1] > 0:#스트라이크 0 이상이라는 가정하에
        for strike in combinations(base,baseball[idx][1]):#스트라이크 개수만큼
            for s in range(0,baseball[idx][1]):
                tmp = baseball[idx][0][strike[s]]
                answer[tmp] = "strike"
            
            for ball in combinations(base,baseball[idx][2]):
                for b in range(0,len(baseball[idx][2])):
                    tmp = baseball[idx][0][ball[b]]
                    if answer[tmp] == "strike": continue
                    else: answer[tmp] = "ball"

                    dfs(idx+1,answer,baseball)

        
        #else:'''

def solution(baseball):
    answer = 0
    ball = [1,2,3,4,5,6,7,8,9]

    for val in permutations(ball,3):
        for i in range(0,len(baseball)):
            play = str(baseball[i][0])

            cnt = 0
            flag = 0
            for j in range(0,3):
                if int(play[j]) == val[j]: 
                    cnt +=1
            if cnt == baseball[i][1]: 
                    flag = 1 #스트라이크 개수 맞으면

            if flag == 0: #스트라이크 개수 안맞음
                break

            cnt = 0
            flag = 0
            for j in range(0,3):
                if int(play[j]) in val: cnt +=1
                
            if (cnt-baseball[i][1]) == baseball[i][2]: flag = 1 #볼 개수 맞으면

            if flag == 0: #볼 개수 안맞음
                break

            if i == (len(baseball) - 1):
                answer +=1
            continue

    #dfs(0,answer, baseball)

    print(answer)
    return answer

if __name__ == "__main__":
    arr = [[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]
    solution(arr)