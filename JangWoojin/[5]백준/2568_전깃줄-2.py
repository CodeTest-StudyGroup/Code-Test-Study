def lower_bound(x, lis):
    lo, hi = 0, len(lis) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if lis[mid] >= x:
            hi = mid - 1
        else:
            lo = mid + 1
    return lo


def solve():
    chk = [False for _ in range(500001)]
    n = int(input())
    a = []
    for _ in range(n):
        i, v = map(int, input().split())
        a.append((i, v))
        chk[i] = True
    a.sort()
    tracking = [(0, 0) for _ in range(n)]
    lis = [a[0][1]]
    tracking[0] = (0, a[0][0])
    for i in range(1, n):
        if a[i][1] > lis[-1]:
            tracking[i] = (len(lis), a[i][0])
            lis.append(a[i][1])
        else:
            lb = lower_bound(a[i][1], lis)
            lis[lb] = a[i][1]
            tracking[i] = (lb, a[i][0])
    idx = len(lis) - 1
    temp = []
    for i in range(n-1, -1, -1):
        if (idx == tracking[i][0]):
            temp.append(tracking[i][1])
            chk[tracking[i][1]] = False
            idx -= 1
    print(n - len(temp))
    for i in range(1, 500001):
        if chk[i]:
            print(i)


if __name__ == '__main__':
    solve()
