import sys
import heapq
import math

t = int(sys.stdin.readline())
for _ in range(t):
    m = int(sys.stdin.readline())
    num_li = []
    for _ in range(math.ceil(m/10)):
        num_li += list(map(int, sys.stdin.readline().split()))
    answer = []

    left, right = [], []
    for i in range(m):
        if len(left) == len(right):
            heapq.heappush(left, (-num_li[i], num_li[i]))

        else:
            heapq.heappush(right, (num_li[i], num_li[i]))

        if right and left[0][1] > right[0][1]:
            left_val = heapq.heappop(left)[1]
            right_val = heapq.heappop(right)[1]
            heapq.heappush(right, (left_val, left_val))
            heapq.heappush(left, (-right_val, right_val))

        if i % 2 == 0:
            median_num = left[0][1]
            answer.append(median_num)

    ans_len = len(answer)
    print(ans_len)
    for i in range(math.ceil(ans_len/10)):
        print(*answer[10*i: min(ans_len, 10 * (i+1))])