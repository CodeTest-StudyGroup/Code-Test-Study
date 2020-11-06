import heapq
import sys
import copy


day = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]  # 일수

if __name__ == "__main__":
    n = int(input())  # 꽃들의 총 개수
    array = []
    for _ in range(n):
        a, b, c, d = map(int, sys.stdin.readline().split())
        start = sum(day[:a]) + b
        end = sum(day[:c]) + d - 1
        array.append((start, end))

    # 피는 시간 순으로 오름차순 정렬
    array.sort()

    limit_day = sum(day[:12])
    current_day = sum(day[:3])
    cnt = 0
    index = 0

    while True:
        temp = 0
        for i in range(index, n):
            if array[i][0] <= current_day + 1:
                temp = max(temp, array[i][1])
                if i == n - 1:
                    if temp < limit_day:
                        print(0)
                        sys.exit(0)
            else:
                index = i
                break
        if temp == 0:
            print(0)
            sys.exit(0)
        current_day = temp
        cnt += 1

        # 종료 조건 확인
        if current_day >= limit_day:
            print(cnt)
            break
