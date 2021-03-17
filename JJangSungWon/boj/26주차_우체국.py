import sys
import math


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = []
    total = 0
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        array.append((a, b))
        total += b
    array.sort()

    prefix_sum = 0
    for i in range(n):
        prefix_sum += array[i][1]
        if prefix_sum >= math.ceil(total / 2):
            print(array[i][0])
            break
