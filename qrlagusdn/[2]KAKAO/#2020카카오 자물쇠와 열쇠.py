#2020카카오 자물쇠와 열쇠

import numpy as np
import copy

def check(key,lock,start_y,start_x):
    for y in range(0,len(key)):
        for x in range(0,len(key)): #key를 lock에 넣기
            lock_y = y+start_y
            lock_x = x+start_x
            if 0<=lock_y<len(lock) and 0<=lock_x<len(lock): #범위가 lock안에 있을때만 확인하기
                if lock[lock_y][lock_x] == 1 and key[y][x] == 1: #둘다 볼록하면 안됨
                    return False
                elif lock[lock_y][lock_x] == 0 and key[y][x] == 1: #들어가면 넣어주기
                    lock[lock_y][lock_x] = 1

    for row in lock: #아직 자물쇠에 안들어간 부분이 있으면 안됨
        if 0 in row:
            return False
    return True

def solution(key, lock):
    answer = False
    for y in range(2-len(lock),len(lock)):
        for x in range(2-len(lock),len(lock)):
            for rot in range(1,5): #시계방향으로 4번돌리기
                tmp_lock = copy.deepcopy(lock)
                tmp_key = np.rot90(key,rot)
                if check(tmp_key,tmp_lock,y,x):
                    return True
    return answer

if __name__ == "__main__":
    print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))