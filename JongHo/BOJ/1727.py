n, m = map(int, input().split())
man = list(map(int, input().split()))
w = list(map(int, input().split()))

man.sort()
w.sort()

def check(a, b):
    p = [[0 for _ in range(len(b)+1)] for _ in range(len(a)+1)]
    for i in range(1, len(a)+1):
        for j in range(i, len(b)+1):
            if i == j:
                p[i][j] = p[i-1][j-1] + abs(a[i-1] - b[j-1])
            else:
                p[i][j] = min(p[i][j-1], p[i-1][j-1] + abs(a[i-1]-b[j-1]))
    return p[len(a)][len(b)]

if n >= m:
    print(check(w, man))
else:
    print(check(man, w))