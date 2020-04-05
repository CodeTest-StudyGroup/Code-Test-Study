import sys

# 1회 상금 (100명)
festival_1 = [0, 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10] + [0] * 80

# 2회 상금 (64명)
festival_2 = [0, 512, 256, 256, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32] + [0] * 70

if __name__ == "__main__":
    T = int(sys.stdin.readline())

    for i in range(T):
        a, b = map(int, sys.stdin.readline().split())

        # 각각의 등수에 맞는 상금 덧셈
        total = (festival_1[a] + festival_2[b]) * 10000

        print(total)