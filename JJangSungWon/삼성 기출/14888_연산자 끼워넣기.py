import sys


def DFS(cnt, value, operation):
    global max_val, min_val

    if cnt == N:
        max_val = max(max_val, value)
        min_val = min(min_val, value)
        return

    for i in range(4):
        if operation[i] != 0:
            operation[i] -= 1
            if i == 0:  # +
                DFS(cnt + 1, value + data[cnt], operation)
            elif i == 1:  # -
                DFS(cnt + 1, value - data[cnt], operation)
            elif i == 2:  # *
                DFS(cnt + 1, value * data[cnt], operation)
            elif i == 3:  # /
                if value < 0:
                    DFS(cnt + 1, -(-value // data[cnt]), operation)
                else:
                    DFS(cnt + 1, value // data[cnt], operation)
            operation[i] += 1


if __name__ == "__main__":
    # input
    N = int(input())
    data = list(map(int, input().split()))
    operation = list(map(int, input().split()))

    max_val = -pow(10, 11)
    min_val = sys.maxsize

    DFS(1, data[0], operation)

    # print
    print(max_val)
    print(min_val)
