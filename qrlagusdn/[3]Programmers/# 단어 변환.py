# 단어 변환

'''
bfs로 풀려고 했는데 중복된 값이 나오는데 처리하기가 곤란했다. 
예를들어 
hit - hot,dot
이 가능한데 hot에서 다시 hit으로 가는 부분을 처리하기가 힘들어서 바로 dfs로 갈아탐
'''

answer = 999999999
def dfs(cnt,visited,begin,target,words):
    global answer
    if begin == target: 
        answer = min(answer,cnt)
    if 0 not in visited: return

    for i in range(0,len(words)):
        if visited[i] == 0:
            flag = 0
            for j in range(0,len(begin)):
                if begin[j] != words[i][j]:
                    flag += 1
                if flag > 1:
                    break
            if flag == 1:#한자리만 다르면  
                visited[i] = 1
                dfs(cnt+1,visited,words[i],target,words)
                visited[i] = 0
            

def solution(begin, target, words):
    global answer
    if target not in words:
        answer = 0
    else:
        visited = [0]*len(words)
        dfs(0,visited,begin,target,words)
    return answer


solution("hit",	"cog",["hot", "dot", "dog", "lot", "log", "cog"])