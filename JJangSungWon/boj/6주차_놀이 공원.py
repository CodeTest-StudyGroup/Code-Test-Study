import sys

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    t_list = list(map(int, sys.stdin.readline().split()))

    if n < m:
        print(n)
    else:
        # 이분 탐색
        left, right = 0, 60000000000
        t = None
        while left <= right:
            mid = (left + right) // 2
            cnt = m
            for i in range(m):
                cnt += mid // t_list[i]
            if cnt >= n:  # n명을 태울 수 있는 상황
                t = mid
                right = mid - 1
            else:
                left = mid + 1

        # t - 1에 탑승한 아이들의 숫자를 계산한다.
        cnt = m
        for i in range(m):
            cnt += (t - 1) // t_list[i]

        # t에 탑승한 아이를 계산한다.
        for i in range(m):
            if t % t_list[i] == 0:  # t 시간에 탑승한 아이
                cnt += 1
            if cnt == n:
                print(i + 1)
                break
