def dfs(cnt, val):
    global max_val

    if cnt >= N:
        max_val = max(max_val, val)
        return
    if cnt + data[cnt][0] <= N:
        dfs(cnt + data[cnt][0], val + data[cnt][1])  # 일을 하는 것
    if cnt + 1 <= N:
        dfs(cnt + 1, val)  # 일을 하지 않고 넘어가는 것


if __name__ == "__main__":
    N = int(input())
    data = [list(map(int, input().split())) for _ in range(N)]

    max_val = -1
    dfs(0, 0)

    print(max_val)
