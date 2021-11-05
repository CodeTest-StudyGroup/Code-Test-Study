import sys
from itertools import permutations
input = sys.stdin.readline

n, k = map(int, input().split())

info = [[0] * (n + 1)]
for _ in range(n):
    hand = [0] + list(map(int, input().split()))
    info.append(hand)

kyung = list(map(int, input().split()))
minho = list(map(int, input().split()))

def dfs(a, b, index, wins, P):
    if wins[0] == k:
        print(1)
        exit(0)        
    
    if index[0] == n:
        return
        
    c = 3 - (a + b)
    p1 = P[a][index[a]]
    p2 = P[b][index[b]]
    index[a] += 1
    index[b] += 1
    
    if info[p1][p2] == 2 or (info[p1][p2] == 1 and a > b):
        wins[a] += 1
        dfs(a, c, index, wins, P)
    elif (info[p1][p2] == 1 and a < b) or info[p1][p2] == 0:
        wins[b] += 1
        dfs(b, c, index, wins, P)

ziu = list(range(1, n+1))
for i in permutations(ziu, n):
    P = [i, kyung, minho]
    index = [0, 0, 0]
    wins = [0, 0, 0]
    dfs(0, 1, index, wins, P)
print(0)