N, K = map(int, input().split())
kindergarten = list(map(int, input().split()))

diff = []
for i in range(N-1):
    sub = kindergarten[i+1] - kindergarten[i]
    diff.append(sub)

# 내림차순
diff.sort()
# N-K번까지의 diff를 더해야지 총 K개의 모임이 나오기 때문
print(sum(diff[:N-K]))

# ref: https://c-king.tistory.com/258
 