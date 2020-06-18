import math


if __name__ == "__main__":

    N = int(input())
    people = list(map(int, input().split()))
    B, C = map(int, input().split())

    total = len(people)
    for i in range(len(people)):
        people[i] -= B
        if people[i] < 0:
            people[i] = 0
        total += math.ceil(people[i] / C)
    print(total)