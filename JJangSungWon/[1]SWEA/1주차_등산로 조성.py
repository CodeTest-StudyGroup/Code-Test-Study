def dfs(cnt, row, col, K, visited):
    global max_cnt

    for i in range(4): # 범위 체크(0 <= 값 < N), 이동할 곳이 현재 값보다 작은지 확인, 방문여부 확인
        if 0 <= row + dx[i] < N and 0 <= col + dy[i] < N and arr[row][col] > arr[row + dx[i]][col + dy[i]] and (row + dx[i], col + dy[i]) not in visited:
            visited.append((row + dx[i], col + dy[i]))
            dfs(cnt + 1, row + dx[i], col + dy[i], K, visited)
            # 다시 원래대로
            visited.remove((row + dx[i], col + dy[i]))
        # K를 써서 통과할 수 있는지 확인
        elif 0 <= row + dx[i] < N and 0 <= col + dy[i] < N and arr[row][col] > arr[row + dx[i]][col + dy[i]] - K and (row + dx[i], col + dy[i]) not in visited:
            visited.append((row + dx[i], col + dy[i]))

            value = -1 # K 값 저장을 위해 선언
            # 제일 큰 K 값을 빼주면 테스트 케이스 중에서 통과하지 못하는 부분이 있다. K 중에서도 가장 작은 값을 활용
            for M in range(1, K + 1):
                if arr[row][col] > arr[row + dx[i]][col + dy[i]] - M:
                    arr[row + dx[i]][col + dy[i]] -= M
                    value = M
                    break
            dfs(cnt + 1, row + dx[i], col + dy[i], 0, visited)

            # 다시 원래대로
            visited.remove((row + dx[i], col + dy[i]))
            arr[row + dx[i]][col + dy[i]] += value

    if cnt > max_cnt:
        max_cnt = cnt
    return


if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):
        N, K = map(int, input().split())
        arr, max_cnt = [], -1

        for i in range(N):
            arr.append(list(map(int, input().split())))

        # 가장 높은 봉우리 찾기
        max_value = -1
        for i in range(N):
            if max_value < max(arr[i]):
                max_value = max(arr[i])

        # 가장 높은 봉우리 인덱스 저장
        index_value = []
        for i in range(N):
            for j in range(N):
                if arr[i][j] == max_value:
                    index_value.append((i, j))

        # 상 하 좌 우
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        for i, j in index_value:
            visited = [(i, j)] # 시작 지점 방문 체크
            dfs(1, i, j, K, visited)

        print("#{} {}".format(tc, max_cnt))
