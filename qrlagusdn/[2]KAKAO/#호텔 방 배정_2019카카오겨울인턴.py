#호텔 방 배정

'''
비트마스크로 접근해서 답은 다 나오는데 효율성을 다 터진다.

다른 방법도 생각해봐야겟다.

def solution(k, room_number):
    answer = []
    room = 0
    for i in range(0,len(room_number)):
        n = room_number[i]
        j = -1
        while 1:
            if n+j >= k: break #배정받을 수 있는 경우만 주어진다고 했으니깐 고려안해도 될 듯
            if room & (1<<n+j) == 0:#방이 비어있다.
                room = room|(1<<n+j) #채워줌
                answer.append(n+j+1)
                break
            j += 1
    return answer
    '''

import sys

sys.setrecursionlimit(10 ** 6)
def find(val,arr):
    if val in arr:
        empty = find(arr[val],arr)
        arr[val] = empty+1
        return empty
    else:
        arr[val] = val+1
        return val

def solution(k,room_number):
    arr = {}
    answer = []
    for i in room_number:
        answer.append(find(i,arr))
    return answer


if __name__ == "__main__":
    print(solution(10,[1,3,4,1,3,1]))
