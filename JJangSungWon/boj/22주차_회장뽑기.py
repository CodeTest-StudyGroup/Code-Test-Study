import sys


INF = 1e10


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    graph = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        graph[i][i] = 0

    while True:
        a, b = map(int, sys.stdin.readline().split())
        if a == -1 and b == -1:
            break
        else:
            graph[a][b] = 1
            graph[b][a] = 1

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    # 회장 후보 점수 찾기
    min_score = INF
    for i in range(1, n + 1):
        min_score = min(min_score, max(graph[i][1:]))

    # min_score와 일치하는 인덱스 찾기
    candidate = []
    for i in range(1, n + 1):
        if min_score == max(graph[i][1:]):
            candidate.append(i)
    candidate.sort()

    print(min_score, len(candidate))
    print(" ".join(map(str, candidate)))