from math import log2,ceil
input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n,m=MIS();pair=[];data=[];maxTree=[0]*(4*n+1);minTree=[1000000001]*(4*n+1)
for _ in range(n):
    data.append(int(input().rstrip()))
for _ in range(m):
    pair.append(list(MIS()))

def maxInit(maxTree,node, start, end): 
    if start==end:
        maxTree[node]=data[start]
        return maxTree[node]
    else:
        maxTree[node]=max(maxInit(maxTree,node*2,start,(start+end)//2),maxInit(maxTree,node*2+1,(start+end)//2+1,end))
        return maxTree[node]

def minInit(minTree,node, start, end): 
    if start==end:
        minTree[node]=data[start]
        return minTree[node]
    else:
        minTree[node]=min(minInit(minTree,node*2,start,(start+end)//2),minInit(minTree,node*2+1,(start+end)//2+1,end))
        return minTree[node]

def maxFind(node, start, end, left, right):
    if left>end or right<start: return 0
    if left<=start and end<=right: return maxTree[node]
    return max(maxFind(node*2, start, (start+end)//2, left, right),maxFind(node*2 + 1, (start+end)//2+1, end, left, right))

def minFind(node, start, end, left, right):
    if left>end or right<start: return 1000000001
    if left<=start and end<=right: return minTree[node]
    return min(minFind(node*2, start, (start+end)//2, left, right),minFind(node*2 + 1, (start+end)//2+1, end, left, right))

maxInit(maxTree,1,0,n-1)
minInit(minTree,1,0,n-1)
for a,b in pair:
    print(minFind(1,0,n-1,a-1,b-1),end=" ")
    print(maxFind(1,0,n-1,a-1,b-1),end=" ")
    print()