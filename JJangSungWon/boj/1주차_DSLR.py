from collections import deque


def bfs(start, end):
    q = deque([[start, ""]])
    visited = [0] * 10000
    visited[start] = True

    while q:
        num, operation = q.popleft()

        if num == end:
            return operation

        # D
        if not visited[num * 2 % 10000]:
            visited[num * 2 % 10000] = True
            q.append([num * 2 % 10000, operation + "D"])
        # S
        if not visited[(num - 1) % 10000]:
            visited[(num - 1) % 10000] = True
            q.append([(num - 1) % 10000, operation + "S"])
        # L
        if not visited[num % 1000 * 10 + num // 1000]:
            visited[num % 1000 * 10 + num // 1000] = True
            q.append([num % 1000 * 10 + num // 1000, operation + "L"])
        # R
        if not visited[num % 10 * 1000 + num // 10]:
            visited[num % 10 * 1000 + num // 10] = True
            q.append([num % 10 * 1000 + num // 10, operation + "R"])


if __name__ == "__main__":

    # input
    T = int(input())
    for _ in range(T):
        A, B = map(int, input().split())
        print(bfs(A, B))
