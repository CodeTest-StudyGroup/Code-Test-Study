import itertools, sys, copy
from collections import deque

if __name__ == "__main__":
    N, M = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(N)]

    # 치킨집 탐색
    chicken = []
    for i in range(N):
        for j in range(N):
            if arr[i][j] == 2:
                chicken.append([i, j])
                arr[i][j] = 0  # 빈 칸으로 수정

    # 치킨집 중에 M개 고르기(조합)
    result = list(itertools.combinations(chicken, M))

    # 탐색
    min_distance = sys.maxsize
    for i in range(len(result)):
        distance = 0
        for m in range(N):
            for n in range(N):
                if arr[m][n] == 1:
                    temp = sys.maxsize
                    for j in range(M):
                        temp = min(temp, abs(m - result[i][j][0]) + abs(n - result[i][j][1]))
                    distance += temp
        min_distance = min(min_distance, distance)

    # 출력
    print(min_distance)
