import heapq
import sys
T = int(input())

for _ in range(T):
    M = int(input())
    elements = []
    input_cnt = M//10 + 1

    for _ in range(input_cnt):
        elements += list(map(int, sys.stdin.readline().split()))

    answer = []
    for i in range(0, M, 2):
        hq = elements[:i+1]
        heapq.heapify(hq)
        cur_loc = i + 1
        mid_loc = cur_loc//2 +1

        for _ in range(mid_loc):
            element = heapq.heappop(hq)
        answer.append(element)

    answer_cnt = len(answer)
    print(answer_cnt)
    for i in range(answer_cnt):
        if i >= 10 and i % 10 == 0:
            print()
        print(answer[i], end = ' ')