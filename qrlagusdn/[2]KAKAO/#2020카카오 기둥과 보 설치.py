#2020카카오 기둥과 보 설치

'''
n은 어따가 쓰노?

대충 조건문 잘 써서 풀면되는 문제!
'''
import copy
def gi_check(x,y,build):
    if y == 0: return True
    if [x-1,y,1] in build or [x,y,1] in build or [x,y-1,0] in build:
        return True
    return False

def bo_check(x,y,build):
    if [x,y-1,0] in build or [x+1,y-1,0] in build or ([x-1,y,1] in build and [x+1,y,1] in build):
        return True
    return False

def solution(n, build_frame):
    answer = []
    for frame in build_frame:
        x,y,a,b = frame[0],frame[1],frame[2],frame[3]
        if b == 1:#설치:
            if a == 0: #기둥
                if gi_check(x,y,answer):
                    answer.append([x,y,a])
            else: #보 
                if bo_check(x,y,answer):
                    answer.append([x,y,a])
        else:#삭제
            flag = 1
            tmp = copy.deepcopy(answer)
            if [x,y,a] in tmp:
                tmp.remove([x,y,a])
                if a == 0: #기둥
                    if [x-1,y+1,1] in tmp:
                        if bo_check(x-1,y+1,tmp) == False:
                            flag = 0
                    if [x,y+1,1] in tmp:
                        if bo_check(x,y+1,tmp) == False:
                            flag = 0
                    if [x,y+1,0] in tmp:
                        if gi_check(x,y+1,tmp) == False:
                            flag = 0
                else: #보 
                    if [x+1,y,0] in tmp:
                        if gi_check(x+1,y,tmp) == False:
                            flag = 0
                    if [x,y,0] in tmp:
                        if gi_check(x,y,tmp) == False:
                            flag = 0
                    if [x-1,y,1] in tmp:
                        if bo_check(x-1,y,tmp) == False:
                            flag = 0
                    if [x+1,y,1] in tmp:
                        if bo_check(x+1,y,tmp) == False:
                            flag = 0
                
                if flag == 1:
                    answer.remove([x,y,a])
    answer = sorted(answer,key=lambda k: (k[0],k[1],k[2]))
    return answer

if __name__ == "__main__":
    print(solution(5,[[0,0,0,1],[0,1,0,1],[0,0,0,0]]))