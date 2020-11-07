import sys

sys.setrecursionlimit(10 ** 9)


def dfs(index, right_cnt, result):
    if len(node[index]) == 1:
        return str(node[index][0])
    else:
        # result.append("(")
        if len(node[node[index][1]]) == 1:
            result.append(node[node[index][1]][0])
        else:
            dfs(node[index][1], right_cnt % 2, result)
        if right_cnt % 2 == 0:
            result.append(node[index][0])
            if node[index][0] == '-':
                right_cnt += 1
        else:
            if node[index][0] == '+':
                result.append('-')
            else:
                result.append('+')
                right_cnt += 1
        if len(node[node[index][2]]) == 1:
            result.append(node[node[index][2]][0])
        else:
            dfs(node[index][2], right_cnt % 2, result)
        # result.append(")")
    return result


if __name__ == "__main__":
    n = int(input())
    node = [[] for _ in range(n * 2)]
    for i in range(1, n + 1):
        node[i] = [int(sys.stdin.readline())]
    for i in range(1, n):
        data = list(map(str, sys.stdin.readline().split()))
        node[i + n] = [data[0], int(data[1]), int(data[2])]

    result = dfs(2 * n - 1, 0, [])

    # num_list = []
    # for i in range(len(result)):
    # if result[i] != '(' and result[i] != ')':
    # num_list.append(result[i])

    plus_list = [result[0]]
    minus_list = []
    for i in range(1, len(result), 2):
        if result[i] == '-':
            #     plus_list.append(result[i + 1])
            # else:
            minus_list.append(result[i + 1])

    num = []
    for i in range(1, n + 1):
        num.append(node[i][0])
    num.sort()

    result = sum(num) - 2 * sum(num[:len(minus_list)])
    print(result)
