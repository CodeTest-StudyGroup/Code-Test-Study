#카카오 코드페스티벌 승부 예측 
#https://www.acmicpc.net/problem/15997
import sys

name1, name2, name3, name4 = map(str,input().split())
nameDic = {name1:0,name2:0,name3:0,name4:0 }
#나라이름 입력받기

for i in range(6):#승점 확률 계산
    string = list(map(str,input().split()))
    A = string[0]
    B = string[1]
    W, D, L = float(string[2]), float(string[3]), float(string[4])

    nameDic[A] += W*3 + D*1
    nameDic[B] += L*3 + D*1

ansDic = {name1:0.0,name2:0.0,name3:0.0,name4:0.0} #본선진출 확률 대입할 리스트
sortDic = sorted(nameDic, key = lambda k : nameDic[k], reverse = True)# 승점확률에 따라 내림차순 정렬

if nameDic[sortDic[0]] == nameDic[sortDic[1]] and nameDic[sortDic[0]] == nameDic[sortDic[2]] and nameDic[sortDic[0]] == nameDic[sortDic[3]] :#상위 4개가 똑같은경우 0.25, 0.25, 0.25. 0.25 4명동점
    ansDic[sortDic[0]] = nameDic[sortDic[0]]*0.25
    ansDic[sortDic[1]] = nameDic[sortDic[1]]*0.25
    ansDic[sortDic[2]] = nameDic[sortDic[2]]*0.25
    ansDic[sortDic[3]] = nameDic[sortDic[3]]*0.25
elif nameDic[sortDic[0]] == nameDic[sortDic[1]] and nameDic[sortDic[0]] == nameDic[sortDic[2]] :#상위 3개가 똑같은 경우 0.3333,0.3333,0.3333, 0 3명동점
    ansDic[sortDic[0]] = nameDic[sortDic[0]]*(1/0.3)
    ansDic[sortDic[1]] = nameDic[sortDic[1]]*(1/0.3)
    ansDic[sortDic[2]] = nameDic[sortDic[2]]*(1/0.3)
    ansDic[sortDic[3]] = nameDic[sortDic[3]]*0.0
elif nameDic[sortDic[1]] == nameDic[sortDic[2]] and nameDic[sortDic[1]] == nameDic[sortDic[3]]:#2 3 4 등이 똑같을 수도 3명동점
    ansDic[sortDic[0]] = nameDic[sortDic[0]]*1.0
    ansDic[sortDic[1]] = nameDic[sortDic[1]]*(1/0.3)
    ansDic[sortDic[2]] = nameDic[sortDic[2]]*(1/0.3)
    ansDic[sortDic[3]] = nameDic[sortDic[3]]*(1/0.3)
elif nameDic[sortDic[1]] == nameDic[sortDic[2]]:#2위 3위가 똑같은 경우 1, 0.5, 0.5, 0 2명동점
    ansDic[sortDic[0]] = nameDic[sortDic[0]]*1.0
    ansDic[sortDic[1]] = nameDic[sortDic[1]]*0.5
    ansDic[sortDic[2]] = nameDic[sortDic[2]]*0.5
    ansDic[sortDic[3]] = nameDic[sortDic[3]]*0.0
else: #그 외는 1, 1, 0 ,0  
    # 1=2,3,4 / 1,2,3=4/ 1,2,3,4
    ansDic[sortDic[0]] = nameDic[sortDic[0]]*1.0
    ansDic[sortDic[1]] = nameDic[sortDic[1]]*1.0
    ansDic[sortDic[2]] = nameDic[sortDic[2]]*0.0
    ansDic[sortDic[3]] = nameDic[sortDic[3]]*0.0

print("%.10f" %(ansDic[name1]))
print("%.10f" %(ansDic[name2]))
print("%.10f" %(ansDic[name3]))
print("%.10f" %(ansDic[name4]))