import itertools


def solution(baseball):
    data = [i for i in range(1, 10)]
    data = list(itertools.permutations(data, 3))
    result = []

    for i in range(len(data)):
        cnt = 0
        for j in range(len(baseball)):
            strike, ball = 0, 0
            temp = list(str(baseball[j][0]).strip())
            for k in range(3):
                if str(data[i][k]) == temp[k]:
                    strike += 1
                elif str(data[i][k]) in temp:
                    ball += 1

            if strike == baseball[j][1] and ball == baseball[j][2]:
                cnt += 1
        if cnt == len(baseball):
            result.append(data[i])

    return len(result)


if __name__ == "__main__":
    baseball = [[123, 1, 1, ], [356, 1, 0], [489, 0, 1]]
    solution(baseball)
