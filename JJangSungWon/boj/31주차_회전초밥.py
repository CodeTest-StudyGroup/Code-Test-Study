from collections import deque
import sys


if __name__ == "__main__":
    n, d, k, c = map(int, sys.stdin.readline().split())
    array = [int(sys.stdin.readline()) for _ in range(n)]

    sushi_dict = dict.fromkeys(array, 0)
    sushi_dict[c] = 0

    window_start, window_end, kind, cnt = 0, 0, 0, 0
    answer = 0
    while window_start != n:
        if cnt >= k:
            if sushi_dict[array[window_start]] == 1:
                kind -= 1
            sushi_dict[array[window_start]] -= 1
            window_start += 1
            cnt -= 1
        else:
            if sushi_dict[array[window_end]] == 0:
                kind += 1
            sushi_dict[array[window_end]] += 1
            window_end = (window_end + 1) % n
            cnt += 1
        if kind >= answer:
            answer = kind
            if sushi_dict[c] == 0:  # 쿠폰
                answer += 1

    print(answer)