import sys
input = sys.stdin.readline

n = int(input())
arr = list(input().rstrip())

al = {}
length = 0

i = 0
j = 0
while j < len(arr):
    if arr[j] not in al:
        al[arr[j]] = 1
    else:
        al[arr[j]] += 1
    
    if len(al) > n:
        length = max(length, j - i)
        while len(al) > n:
            if al[arr[i]] == 1:
                al.pop(arr[i])
            else:
                al[arr[i]] -= 1
            i += 1  
    j += 1
length = max(length, j - i)

print(length)