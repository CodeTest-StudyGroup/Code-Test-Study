def solution():
    ans = '''"'''
    for i in range(len(arr)-1,0, -1):
        ans += arr[i]
    ans += arr[0]
    ans += '''"'''
    return ans

if __name__ == "__main__":
    string = str(input())
    string = string.replace("[","")
    string = string.replace(",","")
    string = string.replace("]","")
    arr = list(map(str,string.split()))
    #print(string)
    #print(arr)

    for i in range(0,len(arr)):
        for j in range(i+1,len(arr)):
            if len(arr[i]) == len(arr[j]):
                for k in range(0, len(arr[i])):
                    if arr[i][k] > arr[j][k]:#자리수 비교
                        tmp = arr[j]
                        arr[j] = arr[i]
                        arr[i] = tmp
                        break
                    elif arr[i][k] == arr[j][k]: continue
                    elif arr[i][k] < arr[j][k] : break
            elif len(arr[i]) > len(arr[j]):
                for k in range(0, len(arr[j])):
                    if arr[i][k] > arr[j][k]:#자리수 비교
                        tmp = arr[j]
                        arr[j] = arr[i]
                        arr[i] = tmp
                        break
                    elif arr[i][k] == arr[j][k]: 
                        if k == len(arr[j])-1:
                            #끝이니깐
                            tmp = arr[j]
                            arr[j] = arr[i]
                            arr[i] = tmp
                        continue
                    elif arr[i][k] < arr[j][k] : break
            elif len(arr[i]) < len(arr[j]):
                for k in range(0, len(arr[i])):
                    if arr[i][k] > arr[j][k]:#자리수 비교
                        tmp = arr[j]
                        arr[j] = arr[i]
                        arr[i] = tmp
                        break
                    elif arr[i][k] == arr[j][k]: 
                        if k == len(arr[i])-1:
                            #끝이니깐
                            if arr[j][k+1] < arr[i][k]:
                                tmp = arr[j]
                                arr[j] = arr[i]
                                arr[i] = tmp
                        continue
                    elif arr[i][k] < arr[j][k] : break
    
    print(solution())
                    
#[6, 10, 2]