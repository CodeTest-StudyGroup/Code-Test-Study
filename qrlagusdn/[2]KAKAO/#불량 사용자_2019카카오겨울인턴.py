#불량 사용자_2019카카오겨울인턴


from itertools import permutations, combinations
import copy

def solve(val,ban):
    if len(val) != len(ban):#길이가 같지않으면
        return 0
    for k in range(0,len(val)):
        if ban[k] == '*': continue
        else:
            if val[k] != ban[k]: #다른값이 나오면 바로 return
                return 0
    return 1

def dfs(arr,idx,visited):
    global value
    if idx >= len(arr):
        tmp = copy.deepcopy(visited)
        tmp.sort()
        if tmp not in value:
            value.append(tmp)
        return
    
    for j in range(0,len(arr[idx])):
        if arr[idx][j] not in visited:
            visited.append(arr[idx][j])
            dfs(arr,idx+1,visited)
            visited.pop()

def solution(user_id, banned_id):
    global value
    answer = 0
    arr = [list() for _ in range(len(banned_id))]
    for i in range(0,len(banned_id)):
        for id in user_id:
            if solve(id,banned_id[i]):
                arr[i].append(id)
    visited = list()
    dfs(arr,0,visited)
    answer = len(value)
    return answer


value = list()
if __name__ == "__main__":
    user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
    banned_id = ["*rodo", "*rodo", "******"]
    print(solution(user_id,banned_id))