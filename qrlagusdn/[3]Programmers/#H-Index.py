#H-Index

'''
호오,,, 생각보다 너무 어려운데? ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
'''

def solution(citations):
    citations = sorted(citations)
    idx = 0
    j = 0
    while j<len(citations):
        if citations[j] >= idx:
            if len(citations) - j >= idx:
                if citations[j] == idx:
                    j+=1
                idx += 1
            else:
                break
        else:
            j+=1

    return idx-1

if __name__ == "__main__":

    print(solution([3, 0, 6, 1, 5]))