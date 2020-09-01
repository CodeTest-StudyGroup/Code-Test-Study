INF = 1e9

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    array = [[5] * n for _ in range(n)]  # 초기 양분 5로 초기화
    nourishment = [[0] * n for _ in range(n)]
    tree = [[[] for _ in range(n)] for _ in range(n)]  # 나무 정보를 저장하는 덱 선언
    for _ in range(m):
        x, y, z = map(int, input().split())
        tree[x - 1][y - 1].append(z)

    year = 0
    while year < k:  # k년 까지 반복
        # 봄 - 나무가 자신의 나이만큼 양분을 먹는다
        for i in range(n):
            for j in range(n):
                if tree[i][j]:  # 나무가 있다면
                    tree[i][j].sort()  # 나이 적은 나무 순서
                    temp = []
                    for age in tree[i][j]:
                        if array[i][j] >= age:
                            array[i][j] -= age  # 나이 만큼 양분 먹기
                            temp.append(age + 1)
                        else:
                            nourishment[i][j] += age // 2
                    tree[i][j] = []
                    tree[i][j].extend(temp)

        # 가을 - 나무 번식
        for i in range(n):
            for j in range(n):
                if tree[i][j]:  # 나무가 있다면
                    for age in tree[i][j]:
                        if age % 5 == 0:  # 나이가 5의 배수이면 번식
                            for dir in range(8):
                                nx, ny = i + dx[dir], j + dy[dir]
                                if 0 <= nx < n and 0 <= ny < n:
                                    tree[nx][ny].append(1)

        # 겨울 - 양분 추가
        for i in range(n):
            for j in range(n):
                array[i][j] += a[i][j] + nourishment[i][j]
                nourishment[i][j] = 0

        year += 1

    # 나무 수 계산
    answer = 0
    for i in range(n):
        for j in range(n):
            answer += len(tree[i][j])
    print(answer)
