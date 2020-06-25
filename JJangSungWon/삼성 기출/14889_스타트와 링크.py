import sys
import itertools


def team(member):
    all_team = [i for i in range(N)]
    start_team = []
    link_team = []

    start_sum = 0
    link_sum = 0

    for i in all_team:
        if i in member:
            start_team.append(i)
        else:
            link_team.append(i)

    for i in start_team:
        for j in start_team:
            start_sum += arr[i][j]

    for i in link_team:
        for j in link_team:
            link_sum += arr[i][j]

    return abs(start_sum - link_sum)


def calculate(members):
    combination_members = itertools.combinations(members, N // 2)
    selected_members = list(combination_members)
    length = len(selected_members) // 2

    minVal = sys.maxsize
    for member in selected_members[:length]:
        minus = team(member)

        if minVal > minus:
            minVal = minus

    print(minVal)


if __name__ == "__main__":
    N = int(sys.stdin.readline())
    members = [i for i in range(N)]
    arr = []

    # input
    for i in range(N):
        arr.append(list(map(int, sys.stdin.readline().split())))

    calculate(members)
