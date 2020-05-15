#입국심사

def solution(n, times):
    answer = 0
    sorted(times)
    table = [[0,times[i]] for i in range(0,len(times))]
    time = 0
    front = 0
    rear = len(times)-1
    arr = [i for i in range(0,len(table))]
    while n>0:
        for i in range(0,len(table)):
            if table[i][0] > 0: #안에 사람이 진행중이면
                table[i][0] -= 1
                if table[i][0] == 0:
                    arr.append(i)
        sorted(arr)

        while 1:
            if not arr or n == 0:
                break
            if n == 1:
                table = sorted(table,key=lambda k: (k[0]+k[1]))
                time += table[0][0]+table[0][1]
                return time
            idx = arr.pop(0)
            table[idx][0] = table[idx][1]
            n -=1

        table = sorted(table,key=lambda k: (k[0]+k[1]))
        
        time += 1
            
    return time
if __name__ == "__main__":

    print(solution(6,[7, 10]))