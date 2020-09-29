from bisect import bisect_right
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    array = sorted(list(map(int, input().split())))
    k_list = list(map(int, input().split()))

    minsu = [False] * (n + 1)

    for i in range(len(k_list)):
        num = bisect_right(array, k_list[i])
        for i in range(num, m):
            if not minsu[array[i]]:
                print(array[i])
                minsu[array[i]] = True
                break



