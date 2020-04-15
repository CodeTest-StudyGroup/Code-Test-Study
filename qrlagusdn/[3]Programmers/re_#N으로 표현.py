#N으로 표현

'''
i 의 값을 구해야할 때 j+k = i 로 했을때
예를 들어
i가 5이면
1 4
2 3
3 2
4 1 
이런 for 문 만드는 점화식이다!

규칙 찾기도 어려웠지만, 점화식만드는 for 문 조건식도 쉽지 않은듯,,,

'''

def solution(N, number):
    answer = 0
    MIN = 10
    arr = [list() for _ in range(9)]
    
    for i in range(1,9):
        arr[i].append(int(str(N)*i))

    for i in range(2,9):
        for j in range(1,i):
            for op1 in arr[j]:
                for op2 in arr[i-j]:
                    arr[i].append(op1+op2)
                    arr[i].append(op1-op2)
                    arr[i].append(op1*op2)
                    if op2 != 0:
                        arr[i].append(op1//op2)
        if number in arr[i]:
            MIN = min(MIN,i)
    
    if MIN == 10:
        answer = -1
    else:
        answer = MIN
    
    print(answer)
    return answer

if __name__ == "__main__":
    N = 5
    number = 12
    solution(N,number)
