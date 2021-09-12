import heapq
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    q, r = divmod(n, 10)
    num = []
    if r == 0:
        for _ in range(q):
            num.extend(list(map(int, input().split())))
    else:
        for _ in range(q + 1):
            num.extend(list(map(int, input().split())))
    
    center1 = []
    center2 = []
    heapq.heappush(center1, num.pop(0))
    print(n//2 + 1)
    print(center1[0], end=" ")
    print_cnt = 1
    while num:
        if len(center1) > 0:
            for _ in range(2):
                heapq.heappush(center1, num.pop(0))
            while center1:
                center2.append(heapq.heappop(center1))
            print(center2[len(center2) // 2], end=" ")
            print_cnt += 1
            if print_cnt == 10:
                print()
                print_cnt = 0
        else:
            for _ in range(2):
                heapq.heappush(center2, num.pop(0))
            while center2:
                center1.append(heapq.heappop(center2))
            print(center1[len(center1) // 2], end=" ")
            print_cnt += 1
            if print_cnt == 10:
                print()
                print_cnt = 0
    print()