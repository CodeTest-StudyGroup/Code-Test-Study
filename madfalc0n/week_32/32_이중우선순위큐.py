
def solution(operations):
    queue = []
    for ops in operations:
        op, num = list(ops.split(' '))
        num = int(num)
        sw = True
        if op == 'I':
            if len(queue) == 0:
                queue.append(num)
            else:
                for i in range(len(queue)):
                    if queue[i] <= num:
                        queue.insert(i,num)
                        sw = True
                        break
                    else:
                        sw = False
                if sw == False:
                    queue.append(num)
        else:
            if len(queue) != 0:
                if num == 1:
                    queue.pop(0)
                else:
                    queue.pop(-1)
        # print(op, num, queue)                
                    
    
    if len(queue) == 0:
        return [0,0]
    elif len(queue) == 1:
        return [queue[0], queue[0]]
    else:
        return [queue[0], queue[-1]]
