input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip());board=[];INF=2e10
for _ in range(n):
    board.append(list(MIS()))
dp=[[None]*(1<<n) for _ in range(n)]

def find_path(last,visited): 
    if visited==(1<<n)-1:  
        return board[last][0] or INF  

    if dp[last][visited] is not None:  
        return dp[last][visited]

    tmp=INF
    for city in range(n):
        if visited&(1<<city)==0 and board[last][city]!=0:
            tmp=min(tmp,find_path(city,visited | (1<<city)) + board[last][city])
    dp[last][visited]=tmp
    return tmp

print(find_path(0,1<<0))