def dfs(row, computers, visited):
    for i in range(len(computers)):
        if computers[row][i] == 1 and visited[row][i] == 0:
            computers[row][i], computers[i][row] = 0, 0
            visited[row][i], visited[i][row] = 0, 0
            dfs(i, computers, visited)


def solution(n, computers):
    answer = 0
    visited = [[0] * len(computers) for _ in range(len(computers))]

    for i in range(len(computers)):
        for j in range(len(computers)):
            if computers[i][j] == 1 and visited[i][j] == 0:
                answer += 1
                computers[i][j], computers[j][i] = 0, 0
                visited[i][j], visited[j][i] = 0, 0
                dfs(j, computers, visited)

    return answer


if __name__ == "__main__":
    print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))