#4013 특이한 자석

'''
진짜 코드가 좀 복잡해지니깐 에러잡기가 너무너무 힘들다....

여러가지 if문으로 커버를 하니깐 어디가 에러난지 하나하나 디버깅하기가 너무 힘들었다.

왠지 더 좋은 코드가 많이 있을 듯 하다...


https://conak-diary.tistory.com/84
충격적인 코드...
100줄짜리 내 코드를 반틈으로 줄였다..
진짜 잘하시네... 충격 그 자체다..
'''

import copy

def rotation(mag, dir):
    tmp = [0]*8
    if dir == 1:
        for i in range(1,8):
            tmp[i] = mag[i-1]
        tmp[0] = mag[7]
    else:
        for i in range(0,7):
            tmp[i] = mag[i+1]
        tmp[7] = mag[0]
    return tmp


if __name__ == "__main__":
    T = int(input())
    for TC in range(T):
        K = int(input())
        MAP = [list(map(int,input().split())) for _ in range(4)]
        rotate = [list(map(int,input().split())) for _ in range(K)]

        for k in range(0,K):
            pos = rotate[k][0]
            dir = rotate[k][1]
            if pos == 2: #2 - 3 - 4 & 2 - 1
                flag = 0
                if MAP[0][2] != MAP[1][6]: flag = 1

                if MAP[1][2] != MAP[2][6]: #2,3
                    if MAP[2][2] != MAP[3][6]: #3,4
                        MAP[1] = rotation(MAP[1],dir)
                        MAP[2] = rotation(MAP[2],-dir)
                        MAP[3] = rotation(MAP[3],dir)
                    else:
                        MAP[1] = rotation(MAP[1],dir)
                        MAP[2] = rotation(MAP[2],-dir)
                else:
                    MAP[1] = rotation(MAP[1],dir)

                if flag == 1: #1,2
                    MAP[0] = rotation(MAP[0],-dir)

            elif pos == 3: # 3 - 2 - 1 & 3 - 4
                flag = 0
                if MAP[2][2] != MAP[3][6]: flag = 1

                if MAP[1][2] != MAP[2][6]: #2,3
                    if MAP[0][2] != MAP[1][6]: #1,2
                        MAP[2] = rotation(MAP[2],dir)
                        MAP[1] = rotation(MAP[1],-dir)
                        MAP[0] = rotation(MAP[0],dir)
                    else:
                        MAP[2] = rotation(MAP[2],dir)
                        MAP[1] = rotation(MAP[1],-dir)
                else:
                    MAP[2] = rotation(MAP[2],dir)

                if flag == 1: #3,4
                    MAP[3] = rotation(MAP[3],-dir)

            elif pos == 1: #1 - 2 - 3 - 4
                if MAP[0][2] != MAP[1][6]: #1,2
                    if MAP[1][2] != MAP[2][6]: #2,3
                        if MAP[2][2] != MAP[3][6]: #3,4
                            MAP[3] = rotation(MAP[3],-dir)
                            MAP[2] = rotation(MAP[2],dir)
                            MAP[1] = rotation(MAP[1],-dir)
                            MAP[0] = rotation(MAP[0],dir)
                        else:
                            MAP[2] = rotation(MAP[2],dir)
                            MAP[1] = rotation(MAP[1],-dir)
                            MAP[0] = rotation(MAP[0],dir)
                    else:
                        MAP[1] = rotation(MAP[1],-dir)
                        MAP[0] = rotation(MAP[0],dir)
                else:
                    MAP[0] = rotation(MAP[0],dir)

            elif pos == 4: #4 - 3 - 2 - 1
                if MAP[2][2] != MAP[3][6]: #3,4
                    if MAP[1][2] != MAP[2][6]: #2,3
                        if MAP[0][2] != MAP[1][6]: #1,2
                            MAP[3] = rotation(MAP[3],dir)
                            MAP[2] = rotation(MAP[2],-dir)
                            MAP[1] = rotation(MAP[1],dir)
                            MAP[0] = rotation(MAP[0],-dir)
                        else:
                            MAP[3] = rotation(MAP[3],dir)
                            MAP[2] = rotation(MAP[2],-dir)
                            MAP[1] = rotation(MAP[1],dir)
                    else:
                        MAP[3] = rotation(MAP[3],dir)
                        MAP[2] = rotation(MAP[2],-dir)
                else:
                    MAP[3] = rotation(MAP[3],dir)
        answer = 0
        j = 1
        for i in range(0,4):
            answer += MAP[i][0]*j
            j *=2
        print("#%d %d" %(TC+1,answer))
    
