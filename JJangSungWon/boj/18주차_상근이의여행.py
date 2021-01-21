import sys


if __name__ == "__main__":
    for _ in range(int(sys.stdin.readline())):
        n, m = map(int, sys.stdin.readline().split())
        for _ in range(m):
            a, b = map(int, sys.stdin.readline().split())  # n - 1이 정답이므로 a, b 입력은 의미없다.
        print(n - 1)