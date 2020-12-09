import sys
input=sys.stdin.readline
MIS=lambda:map(int,input().rstrip().split())
n=int(input().rstrip());data=list(MIS())

if n==1: print('A')
elif n==2:
    if data[0]==data[1]: print(data[0])
    else: print('A')
else:
    flag=True
    for i in range(len(data)-1):
        if i==0:
            one,two,three=data[i],data[i+1],data[i+2]
            if two-one==0: a=0;b=two
            else: a=(three-two)//(two-one);b=two-(one*a)
        num1=data[i]*a+b; num2=data[i+1]
        if num1!=num2: flag=False
    
    if flag: print(data[-1]*a+b)
    else: print('B')