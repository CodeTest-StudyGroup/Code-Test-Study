#4014 swea 활주로 건설
'''
ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
어거지로 진짜 겨우풀었다..
ㅋㅋㅋㅋㅋ
그래도 도움안받고 혼자 품..

코드가 쓰레기 코드임
내일 조금씩 참고하면서 정리해보자!
'''

def check(val,X):
    next_next = 0
    cur_cnt, next_cnt ,next_next_cnt= 0,0,0
    pos_next, pos_next_next = 0,0
    flag = 1

    count = 0
    idx = 0
    check = 0
    while 1:
        if val[idx] != val[idx+1]:

            if count == 0: 
                pos_next = idx + 1
                cur_cnt +=1
            elif count == 1:
                pos_next_next = idx + 1
                next_cnt += 1
            elif count == 2:
                next_next_cnt += 1
            
            count += 1
            if count >= 3: 
                check = 1
                break
        else:
            if count == 0: 
                cur_cnt += 1
            elif count == 1: 
                next_cnt += 1
            else: 
                next_next_cnt += 1
        
        idx += 1
        if idx >= len(val)-1:
            if count == 0:
                cur_cnt += 1
            elif count == 1:
                next_cnt += 1
            elif count == 2:
                next_next_cnt +=1
            
            if count == 2: check = 1
            break
    cur,next,next_next = val[0],val[pos_next],val[pos_next_next]

    while 1:
        #DD, DU, UD, UU
        #if idx < len(val): #next_next 존재
        if check == 1:
            if abs(next-cur) > 1 or abs(next-next_next)>1:
                flag = 0
                break
            if next < cur:#Down
                if next_next < next: #Down
                    if next_cnt < X or next_next_cnt < X: 
                        flag = 0
                        break
                elif next_next > next: #UP
                    if next_cnt < 2*X:  
                        flag = 0
                        break
            elif next>cur:#UP
                if next_next < next: #Down
                    if cur_cnt < X or next_next_cnt < X:  
                        flag = 0
                        break
                elif next_next > next: #UP
                    if cur_cnt < X or next_cnt < X: 
                        flag = 0
                        break
            
            cur = next
            cur_cnt = next_cnt
            next = next_next
            next_cnt = next_next_cnt
            idx = idx+1
            if idx < len(val): #next_next 있음
                check = 1
                next_next = val[idx]
                next_next_cnt = 1

                while idx<len(val)-1: #next_next의 길이
                    if val[idx] == val[idx+1]: next_next_cnt+=1
                    else: 
                        break
                    idx += 1
            else:
                check = 0

        else: #next_next 없음
            if abs(next-cur) > 1:
                flag = 0
                break
            if next < cur: #Down
                if next_cnt < X: 
                    flag = 0
                    break
            elif next > cur: #UP
                if cur_cnt < X: 
                    flag = 0
                    break
            break

    if flag == 1:
        return 1
    else: return 0

if __name__ == "__main__":
    T = int(input())
    for TC in range(1,T+1):
        N, X = map(int,input().split())
        MAP = [list(map(int,input().split())) for _ in range(N)]
        answer = 0
        arr = []
        for i in range(0,N): arr.append(MAP[i])
        for i in range(0,N):
            tmp = []
            for j in range(0,N):
                tmp.append(MAP[j][i])
            arr.append(tmp)
        
        for val in arr:
            answer += check(val,X)
        print("#%d %d" %(TC, answer))
