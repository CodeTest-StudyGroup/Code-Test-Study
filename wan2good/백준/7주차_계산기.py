n = int(input().rstrip())
result = []
while n:
    if n&1: 
        result.append('[/]')
        n*=2
    elif n&2: 
        result.append('[+]')
        n-=2
    else: 
        result.append('[*]')
        n//=2
        
print(len(result))
print(' '.join(result[::-1]))