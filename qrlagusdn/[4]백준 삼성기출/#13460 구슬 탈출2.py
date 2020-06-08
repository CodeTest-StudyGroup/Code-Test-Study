#13460 구슬 탈출2

import sys
import math
from collections import deque
import copy
input=sys.stdin.readline
INF=sys.maxsize

dy=[-1,1,0,0]
dx=[0,0,-1,1]

def move(y,x,flag,MAP,color,dir):
   ny,nx=y,x
   while 1: #R이 벽에 부딪히기 전까지 감
      ny+=dy[dir]
      nx+=dx[dir]
      if MAP[ny][nx]=="O":#가는도중에 빠짐
         if flag=='R':
            flag='RB'
         else:
            if color=='R':flag = 'R'
            else:flag='B'
         break
      if MAP[ny][nx]=="#":
         ny,nx=ny-dy[dir],nx-dx[dir]
         break
   return ny,nx,flag

def bfs(MAP,ry,rx,by,bx):
   queue=deque()
   queue.append((ry,rx,by,bx,0))
   visited=[[ry,rx,by,bx]]
   while queue:
      ry,rx,by,bx,cnt=queue.popleft()
      if cnt>9: return -1
      for dir in range(0,4):
         flag = 0
         nry,nrx,flag= move(ry,rx,flag,MAP,'R',dir)
         nby,nbx,flag= move(by,bx,flag,MAP,'B',dir)
         if flag==0 and [nry,nrx]==[nby,nbx]:#구멍에 아무도 안빠졌는데 겹쳐버린다
            if rx==bx: #y 축선상
               if dir==0:
                  if ry<by: #R이 B위에있음
                     nby+=1
                  else:
                     nry+=1
               elif dir==1:
                  if ry<by: #R이 B위에있음
                     nry-=1
                  else:
                     nby-=1

            elif ry==by:#x 축선상
               if dir==2:# 좌
                  if rx<bx: #R B
                     nbx+=1
                  else:
                     nrx+=1
               elif dir==3: #우
                  if rx<bx: #R B
                     nrx-=1
                  else:
                     nbx-=1
         
         if flag=='R':
            return cnt+1
         elif flag==0:
            if [nry,nrx,nby,nbx] not in visited:
               queue.append((nry,nrx,nby,nbx,cnt+1))
               visited.append([nry,nrx,nby,nbx])
   return -1

if __name__ == "__main__":
   #n 세로, m 가로
   #가장 바깥 행,열 모두 막힘.
   row, col=map(int,input().split())
   MAP=[list(input().rstrip()) for _ in range(row)]
   for y in range(0,row):
      for x in range(0,col):
         if MAP[y][x]=='R':
            ry,rx=y,x
         elif MAP[y][x]=='B':
            by,bx=y,x
   print(bfs(MAP,ry,rx,by,bx))