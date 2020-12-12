import sys


def around_grow(array):
    for i in range(1, m):
        for j in range(1, m):
            array[i][j] += array[0][j] - 1


def grow(array, grow_array):  # g 배열을 활용하여 애벌래 크기 증가
    cnt = 0
    for j in range(m - 1, -1, -1):
        array[j][0] += grow_array[cnt]
        cnt += 1
    for j in range(1, m):
        array[0][j] += grow_array[cnt]
        cnt += 1


if __name__ == "__main__":
    m, n = map(int, sys.stdin.readline().split())
    array = [[1] * m for _ in range(m)]
    # 애벌래 초기 배열 선언
    grow_array = [0] * (2 * m - 1)
    for _ in range(n):
        a, b, c = map(int, sys.stdin.readline().split())
        for i in range(a, a + b):
            grow_array[i] += 1
        for i in range(a + b, 2 * m - 1):
            grow_array[i] += 2

    grow(array, grow_array)
    around_grow(array)

    for i in range(m):
        print(" ".join(map(str, array[i])))