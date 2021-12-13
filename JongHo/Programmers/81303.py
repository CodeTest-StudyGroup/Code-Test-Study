from collections import defaultdict

def solution(n, k, cmd):
    answer = ['O'] * n
    l_list = defaultdict(list)
    
    for i in range(1, n + 1):
        l_list[i].append(i - 1)
        l_list[i].append(i + 1)
    
    deleted = []
    k += 1
    
    for com in cmd:
        c = com.split()
        
        if c[0] == "D":
            for _ in range(int(c[1])):
                k = l_list[k][1]
        elif c[0] == "U":
            for _ in range(int(c[1])):
                k = l_list[k][0]
        elif c[0] == "C":
            prev, next = l_list[k]
            deleted.append([prev, next, k])
            answer[k - 1] = "X"
            
            if next == n + 1:
                k = l_list[k][0]
            else:
                k = l_list[k][1]
            
            if prev == 0:
                l_list[next][0] = prev
            elif next == n + 1:
                l_list[prev][1] = next
            else:
                l_list[prev][1] = next
                l_list[next][0] = prev
        else:
            prev, next, now = deleted.pop()
            answer[now - 1] = "O"
            
            if prev == 0:
                l_list[next][0] = now
            elif next == n + 1:
                l_list[prev][1] = now
            else:
                l_list[prev][1] = now
                l_list[next][0] = now
    
    return "".join(answer)