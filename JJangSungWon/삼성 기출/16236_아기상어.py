from collections import deque

# 상, 하, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = 1e9


def bfs(row, col):
    q = deque()
    q.append([0, row, col])  # 이동 횟수, 위치
    visited = set()  # 방문 확인
    visited.add((row, col))

    result = []
    flag = False
    while q:
        cnt, x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if array[nx][ny] > array[row][col]:  # 자신의 크기보다 큰 물고기가 있는 칸은은 지나갈수 없다.
                    continue
                elif (array[nx][ny] == 0 or array[nx][ny] == array[row][col]) and (nx, ny) not in visited:
                    q.append([cnt + 1, nx, ny])  # 통과
                    visited.add((nx, ny))
                elif array[nx][ny] < array[row][col] and (nx, ny) not in visited:  # 먹이 발견
                    flag = True
                    # q.append([cnt + 1, nx, ny])
                    visited.add((nx, ny))
                    result.append([nx, ny, cnt + 1])

    if not flag:  # 먹이가 없는 상황
        return False
    return result


if __name__ == "__main__":
    n = int(input())  # 공간의 크기
    array = [list(map(int, input().split())) for _ in range(n)]

    # 물고기, 아기 상어 위치 파악
    baby = []
    fish = []
    for i in range(n):
        for j in range(n):
            if array[i][j] == 9:
                baby = [i, j]
                array[i][j] = 2
            elif 1 <= array[i][j] <= 6:
                fish.append([i, j])

    day = 0
    food_count = 0
    baby_size = 2
    food_list = []
    while True:
        if len(fish) == 0:  # 먹을 수 있는 물고기가 공간에 없다면
            break
        answer = bfs(baby[0], baby[1])
        if not answer:  # 먹이가 없는 경우
            break
        food_count += 1
        # 거리가 가장 가까운 먹이 찾기
        min_length = INF
        answer = sorted(answer, key=lambda x: (x[2], x[0], x[1]))
        day += answer[0][2]
        array[baby[0]][baby[1]] = 0  # 원래 아기 상어 위치 0 값으로 업데이트
        baby[0], baby[1] = answer[0][0], answer[0][1]
        fish.remove([answer[0][0], answer[0][1]])

        if food_count >= baby_size:
            baby_size += 1
            food_count = 0
        array[baby[0]][baby[1]] = baby_size  # 아기 상어 크기로 업데이트

    # 출력
    print(day)