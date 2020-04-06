import sys
 
def A_money(a):
    if a==0 or a>21: return 0
    elif a==1: return 5000000
    elif a>1 and a<=3: return 3000000
    elif a>3 and a<=6: return 2000000
    elif a>6 and a<=10: return 500000
    elif a>10 and a<=15: return 300000
    elif a>15 and a<=21: return 100000
 
def B_money(b):
    if b == 0 or b>31: return 0
    elif b==1: return 5120000
    elif b>1 and b<=3: return 2560000
    elif b>3 and b<=7: return 1280000
    elif b>7 and b<=15: return 640000
    elif b>15 and b<=31: return 320000
 
T = int(input())
for TC in range(T):
    a, b = map(int, input().split())
    sum = A_money(a) + B_money(b)
    print(sum)