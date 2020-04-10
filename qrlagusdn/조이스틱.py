def solution(name):
    name = name.replace('''"''',"")
    answer = 0
    print(name)
    pos = 0
    arr = ['A' for _ in range(len(name))]
    i = 0
    while 1:
        if ''.join(arr) == name:
            break

        if name[i] == 'A':
            k = i
            while 1:
                if name[k] != 'A':
                    #k까지가는것
                    answer += min((k-pos),(len(name)-k+pos))
                    pos = k
                    break
                k += 1
            if 12 >= (ord(name[i]) - ord('A')):
                answer +=(ord(name[i]) - ord('A'))
            else:
                answer += (ord('Z')-ord(name[i]) + 1)

        elif name[i] != 'A':
            if (i-pos) <((len(name)-i) + (pos+1)):
                answer += i-pos
            else:
                answer += ((len(name)-i) + (pos+1))
            pos = i
            

            if 12 >= (ord(name[i]) - ord('A')):
                answer +=(ord(name[i]) - ord('A'))
            else:
                answer += (ord('Z')-ord(name[i]) + 1)
        
        arr[i] = name[i]
        
        
        i += 1
        
    return answer

if __name__ == "__main__":
    string = str(input())
    answer = solution(string)
    print(answer)