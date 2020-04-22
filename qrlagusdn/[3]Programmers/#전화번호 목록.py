#전화번호 목록
def solution(phone_book):
    answer = True
    for i in range(0,len(phone_book)):
        for j in range(0,len(phone_book)):
            if i == j or len(phone_book[i]) > len(phone_book[j]): continue
                
            for k in range(0,len(phone_book[i])):
                if phone_book[i][k] != phone_book[j][k]: break
                else:
                    if k == len(phone_book[i])-1: 
                        return False
    return answer