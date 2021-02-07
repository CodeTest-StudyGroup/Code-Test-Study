import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())

n=int(input().rstrip()); ball=[]
for i in range(n):
    color,size=MIS()
    ball.append([color,size,i])

ball=sorted(ball,key=lambda x:x[1])

player=[0]*(n+1)
color=[0]*(n+1)
j=0;sum_=0
for i in range(n):
    while ball[j][1]<ball[i][1]:
        sum_+=ball[j][1]
        color[ball[j][0]]+=ball[j][1]
        j+=1
    player[ball[i][2]]=sum_-color[ball[i][0]]

for i in range(n):
    print(player[i])