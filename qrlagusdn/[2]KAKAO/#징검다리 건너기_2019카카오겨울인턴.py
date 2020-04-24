

def check(stones,mid,k):
    for i in range(0,len(stones)):
        if stones[i] < mid:
            stones[i] = 0
    
    cnt = 0
    for i in range(0,len(stones)):
        if stones[i] == 0:
            cnt += 1
        else:
            cnt = 0
            
        if cnt == k:
            return 0
    return 1


def solution(stones, k):
    MAX = max(stones)+1
    MIN = 1 #최소 한명 가능
    while 1:
        if MAX-MIN == 1:
            answer = MIN
            break
        MID = (MAX + MIN)//2
        tmp = list(stones)
        if check(tmp,MID,k):
            MIN = MID
        else:
            MAX = MID
    return answer

if __name__ == "__main__":
    print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))