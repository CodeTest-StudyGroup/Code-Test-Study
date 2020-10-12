import sys


dr = [-1, 0, 1]
dc = [1, 1, 1]


def dfs(row, col):
    if col == c - 1:
        return True

    for i in range(3):
        new_r, new_c = row + dr[i], col + dc[i]
        if 0 <= new_r < r and 0 <= new_c < c:
            if maps[new_r][new_c] == "." and (new_r, new_c) not in visited:
                visited.add((new_r, new_c))
                if dfs(new_r, new_c):
                    return True
    return False


if __name__ == "__main__":
    r, c = map(int, sys.stdin.readline().split())
    maps = [list(sys.stdin.readline().strip()) for _ in range(r)]

    answer = 0
    visited = set()
    for i in range(r):
        flag = dfs(i, 0)
        if flag:
            answer += 1

    print(answer)
