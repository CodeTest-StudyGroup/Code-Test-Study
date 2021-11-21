import sys
input = sys.stdin.readline

def need(width):
    prev = -1
    ret = 0
    for pos in m_x:
        if prev == -1:
            prev = pos
            ret += 1
        elif prev + width <= pos:
            prev = pos
            ret += 1
    
    return ret

r, c = map(int, input().split())
n = int(input())
mistake = int(input())

max_h = 0
m_x = []

for _ in range(mistake):
    m_r, m_c = map(int, input().split())
    max_h = max(max_h, m_r)
    if m_c not in m_x:
        m_x.append(m_c)

m_x.sort()

start = max_h
end = 1000000
while start < end:
    m = (start + end) // 2
    if need(m) <= n:
        end = m
    else:
        start = m + 1