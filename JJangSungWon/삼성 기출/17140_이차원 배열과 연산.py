from collections import Counter


def r_operation(arr):  # R 연산
    for i in range(len(arr)):
        temp = []
        for j in range(len(arr[i])):
            if arr[i][j] != 0:
                temp.append(arr[i][j])

        counter = Counter(temp)
        temp = []
        for key in counter.keys():
            temp.append((key, counter[key]))
        temp = sorted(temp, key=lambda x: (x[1], x[0]))
        for j in range(50):
            if j < len(temp):
                arr[i][j * 2] = temp[j][0]
                arr[i][j * 2 + 1] = temp[j][1]
            else:
                arr[i][j * 2] = 0
                arr[i][j * 2 + 1] = 0
    return arr


def c_operation(arr):  # C 연산
    for i in range(len(arr)):
        temp = []
        for j in range(len(arr)):
            if arr[j][i] != 0:
                temp.append(arr[j][i])

        counter = Counter(temp)
        sort_arr = []
        for key in counter.keys():
            sort_arr.append((key, counter[key]))

        sort_arr = sorted(sort_arr, key=lambda x: (x[1], x[0]))
        for j in range(50):
            if j < len(sort_arr):
                arr[j * 2][i] = sort_arr[j][0]
                arr[j * 2 + 1][i] = sort_arr[j][1]
            else:
                arr[j * 2][i] = 0
                arr[j * 2 + 1][i] = 0
    return arr


def find_col_index(arr):
    index = 0
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i][j] == 0:
                index = max(index, j)
                break
    return index


def find_row_index(arr):
    index = 0
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[j][i] == 0:
                index = max(index, j)
                break
    return index


if __name__ == "__main__":
    R, C, K = map(int, input().split())
    array = [[0] * 101 for _ in range(101)]
    for i in range(3):
        a, b, c = map(int, input().split())
        array[i][0], array[i][1], array[i][2] = a, b, c

    flag = True
    for i in range(0, 101):
        if array[R - 1][C - 1] == K:
            print(i)
            flag = False
            break
        if find_row_index(array) >= find_col_index(array):
            array = r_operation(array)
        else:
            array = c_operation(array)

    if flag:
        print(-1)