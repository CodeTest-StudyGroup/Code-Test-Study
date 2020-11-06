import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))


def go(idx, color):
    temp = arr[idx]
    arr[idx] = color
    i, j = idx, idx
    ret = n
    while i >= 0 and j < n:
        cnt = 0
        c = arr[i]
        while i >= 0 and arr[i] == c:
            i -= 1
            cnt += 1
        while j < n and arr[j] == c:
            j += 1
            cnt += 1
        if cnt < 4:
            break
        ret -= cnt
    arr[idx] = temp
    return ret + 1


answer = 10000
for i in range(n):
    for j in range(1, 4):
        if arr[i] != j:
            answer = min(answer, go(i, j))
print(answer)
