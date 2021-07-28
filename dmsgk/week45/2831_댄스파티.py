# 댄스파티
import sys

ans = 0
n = int(sys.stdin.readline().rstrip())

m_min, m_plus = [], []
w_min, w_plus = [], []

if n == 1:
    man = int(sys.stdin.readline().rstrip())
    woman = int(sys.stdin.readline().rstrip())

    if man > 0:
        m_plus.append(man)
    else:
        m_min.append(man)

    if woman > 0:
        w_plus.append(woman)
    else:
        w_min.append(woman)
else:
    m_li = list(map(int, sys.stdin.readline().rstrip().split()))
    w_li = list(map(int, sys.stdin.readline().rstrip().split()))
    for m in m_li:
        if m > 0:
            m_plus.append(m)
        else:
            m_min.append(m)
    for w in w_li:
        if w > 0:
            w_plus.append(w)
        else:
            w_min.append(w)

    m_plus.sort()
    m_min.sort()
    w_plus.sort()
    w_min.sort()


for mp in m_plus:
    if w_min:
        wm = -w_min.pop()
        while mp >= wm and w_min:
            wm = -w_min.pop()
        if mp < wm:
            ans += 1

for wp in w_plus:
    if m_min:
        mm = -m_min.pop()
        while wp >= mm and m_min:
            mm = -m_min.pop()
        if wp < mm:
            ans += 1

print(ans)