#튜플_2019카카오겨울인턴
#생각보다 어려움??...

#문제 해석이 조금 힘들었다.

def solution(s):
    answer = []
    val = ""
    arr=list()
    tup = []
    for i in range(0,len(s)):
        if s[i] == '{':
            continue
        elif s[i] == '}':
            if (not val) and (not tup): continue
            tup.append(val)
            arr.append(tup)
            tup = []
            val = ""
        elif s[i] ==',':
            if val != "":
                tup.append(val)
                val = ""
        else:
            val += s[i]

    arr=sorted(arr,key=len)
    for i in range(0,len(arr)):
        for j in range(0,len(arr[i])):
            if int(arr[i][j]) not in answer:
                answer.append(int(arr[i][j]))
    return answer

if __name__ == "__main__":
    s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"

    print(solution(s))