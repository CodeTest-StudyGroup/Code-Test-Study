import sys

sys.setrecursionlimit(10 ** 9)


def visit(start):
    visited[start] = True
    totals[start][0] = towns[start]["pop"]
    for index in towns[start]["nearby"]:
        if not visited[index]:
            visit(index)  # visit indexed town.
            totals[start][0] += totals[index][1]  # when current town not selected
            totals[start][1] += max(totals[index])  # when current town selected


n = int(input())
towns = [{"pop": 0, "nearby": []} for _ in range(n)]
for i, population in enumerate(list(map(int, input().split()))):
    towns[i]["pop"] = population

for _ in range(n - 1):
    a, b = map(int, input().split())
    # Dual appending and reduces every number by 1
    towns[a-1]["nearby"].append(b-1)
    towns[b-1]["nearby"].append(a-1)

visited = [False for _ in range(n)]
totals = [[0, 0] for _ in range(n)]

visit(0)

answer = 0
for i in range(n):
    answer = max(answer, max(totals[i]))
print(answer)
