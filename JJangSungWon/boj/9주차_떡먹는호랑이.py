def solve(pre, last):
    for _ in range(d - 2, 0, -1):
        temp = last - pre
        last = pre
        pre = temp
        if pre >= last:
            return False, pre, last
    return True, pre, last


if __name__ == "__main__":
    d, k = map(int, input().split())

    pre_value = k - 1

    for i in range(k - 1, 1, -1):
        flag, a, b = solve(i, k)
        if flag:
            print(a)
            print(b)
            break
