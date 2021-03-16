def solve(idx):
    while idx < len(string):
        min_index = idx
        for i in range(idx, len(string)):
            if string[i] < string[min_index] and not flag[i]:
                min_index = i

        if flag[min_index]:
            return

        flag[min_index] = True
        temp = ""
        for i in range(len(string)):
            if flag[i]:
                temp += string[i]
        print(temp)
        solve(min_index + 1)


if __name__ == "__main__":
    string = list(input())
    flag = [False] * len(string)

    solve(0)