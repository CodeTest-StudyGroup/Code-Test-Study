T = int(input())

for _ in range(T):
    n, m , k = list(map(int, input().split()))
    houses = list(map(int, input().split()))
    answer = 0
    # 첫 m개의 집을 털었을 경우를 money에 저장
    money = sum(houses[:m])
    if money < k:
        answer += 1
    
    if n == m:
        print(answer)
        continue
    
    for i in range(m, n):
        # 1,2,3 4가 있다면 (1,2,*3)(2,3,*4),(3,4,*1),(4,1,*2) 각 money는
        # 각 집합의 마지막 원소들의 차이만큼 차이가 난다
        sub = houses[i] - houses[i-m]
        money = money + sub
        if money < k:
            answer += 1
    
    # 원으로 연결되어 있으니까 뒤에서 앞으로 연결되는 부분 처리
    for j in range(m-1):
        sub = houses[j] - houses[j-m]
        money = money + sub
        if money < k:
            answer += 1
    
    print(answer)