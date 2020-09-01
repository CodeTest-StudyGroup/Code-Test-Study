# 우, 상, 좌, 하
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]


if __name__ == "__main__":
    n = int(input())  # 드래곤 커브의 개수
    data = [list(map(int, input().split())) for _ in range(n)]
    connect = [[] for _ in range(n)]  # 각 드래곤 커브가 연결된 선분 저장

    for i in range(n):  # 드래곤 커브 이동
        x, y, d, g = data[i]
        connect[i].append(d)  # 방향 삽입
        for _ in range(g):  # 세대 수 만큼 반복
            reverse = list(reversed(connect[i]))
            for j in reverse:
                if j + 1 == 4:
                    connect[i].append(0)
                else:
                    connect[i].append(j + 1)

    arr = [[False] * 101 for _ in range(101)]  # 정사각형 지도 초기화
    # 드래곤 커브 이동 값 지도 반영
    for i in range(n):
        x, y, d, g = data[i]
        arr[y][x] = True
        for j in connect[i]:
            x, y = x + dx[j], y + dy[j]
            if 0 <= x <= 100 and 0 <= y <= 100:
                arr[y][x] = True

    # 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 파악
    answer = 0
    for i in range(100):
        for j in range(100):
            if arr[i][j] and arr[i][j + 1] and arr[i + 1][j] and arr[i + 1][j + 1]:
                answer += 1

    print(answer)
