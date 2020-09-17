import copy

INF = 1e9


def solve(x, y, d1, d2):
    temp = [[0] * (n + 1) for _ in range(n + 1)]
    temp[x][y] = 5
    for i in range(1, d1 + 1):
        temp[x + i][y - i] = 5
    for i in range(1, d2 + 1):
        temp[x + i][y + i] = 5
    for i in range(1, d2 + 1):
        temp[x + d1 + i][y - d1 + i] = 5
    for i in range(1, d1 + 1):
        temp[x + d2 + i][y + d2 - i] = 5

    people = [0] * 5
    for r in range(1, x + d1):
        for c in range(1, y + 1):
            if temp[r][c] == 5:
                break
            else:
                people[0] += maps[r][c]

    for r in range(1, x + d2 + 1):
        for c in range(n, y, -1):
            if temp[r][c] == 5:
                break
            else:
                people[1] += maps[r][c]

    for r in range(x + d1, n + 1):
        for c in range(1, y - d1 + d2):
            if temp[r][c] == 5:
                break
            else:
                people[2] += maps[r][c]

    for r in range(x + d2 + 1, n + 1):
        for c in range(n, y - d1 + d2 - 1, -1):
            if temp[r][c] == 5:
                break
            else:
                people[3] += maps[r][c]

    people[4] = total - sum(people)
    return max(people) - min(people)


if __name__ == "__main__":
    n = int(input())
    maps = [[0] * (n + 1)] + [[0] + list(map(int, input().split())) for _ in range(n)]

    total = 0
    for i in range(1, n + 1):
        total += sum(maps[i])

    answer = INF
    for x in range(1, n + 1):
        for y in range(1, n + 1):
            for d1 in range(1, n + 1):
                for d2 in range(1, n + 1):
                    if x + d1 + d2 > n:
                        continue
                    if y - d1 < 1:
                        continue
                    if y + d2 > n:
                        continue

                    answer = min(answer, solve(x, y, d1, d2))

    print(answer)
