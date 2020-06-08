#13458 시험 감독

import sys
import math
from collections import deque
import copy
input=sys.stdin.readline
INF=sys.maxsize

if __name__ == "__main__":
   n=int(input())
   arr=list(map(int,input().split()))
   b,c=map(int,input().split())
   MAX=max(arr)
   dp=[1]*(MAX+1)

   idx=1
   cnt=0
   for i in range(b+1,MAX+1):
      dp[i]+=idx
      cnt+=1
      if cnt==c:
         idx+=1
         cnt=0

   ans=0
   for i in range(0,n):
      ans+=dp[arr[i]]

   print(ans)