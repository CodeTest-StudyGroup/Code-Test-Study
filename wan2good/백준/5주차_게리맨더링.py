import sys
from collections import deque
import math
from itertools import combinations
input = sys.stdin.readline

n = int(input().rstrip())
populations = list(map(int, input().rstrip().split()))
populations.insert(0, 0)

graph = [[] for _ in range(n+1)]
for i in range(1,n+1):
    data = list(map(int,input().rstrip().split()))
    for j in range(1,data[0]+1):
        graph[i].append(data[j])

def is_group(start, candidates):
    queue = deque()
    queue.append(start)
    count = 1
    visited = set()
    while queue:

        y = queue.popleft()
        visited.add(y)
        # for x in range(len(maps[y])):
        for i in graph[y]:
            if i in candidates and i not in visited:
                queue.append(i)
                visited.add(i)
                count += 1            
    if count == len(candidates):
        return True
    return False

maxValue = 987654321

for i in range(1, (n // 2 + 1)):
    candidates = combinations(range(1, n+1), i)
    for one in candidates:
        one = list(one)
        other = list(set(range(1,n+1)) - set(one))
        if is_group(one[0], set(one)) and is_group(other[0], set(other)):
            one_value = [populations[i] for i in one]
            other_value = [populations[i] for i in other]
            maxValue = min(maxValue, abs(sum(one_value) - sum(other_value)))


print(maxValue if maxValue!=987654321 else -1)