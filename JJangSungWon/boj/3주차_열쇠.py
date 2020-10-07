from collections import deque


dx = [0, -1, 1, 0, 0]
dy = [0, 0, 0, -1, 1]


def bfs(q, location):
    answer = 0  # 문서의 개수
    visited = set()

    while q:
        x, y = q.popleft()
        for i in range(5):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if (nx, ny) in visited:
                    continue
                if maps[nx][ny] == "$":
                    answer += 1
                elif maps[nx][ny] == ".":
                    pass
                elif maps[nx][ny] == "*":
                    continue
                else:
                    if "a" <= maps[nx][ny] <= "z":
                        h_keys.add(maps[nx][ny])
                    elif "A" <= maps[nx][ny] <= "Z":
                        if maps[nx][ny].lower() in h_keys:
                            pass
                        else:
                            location.append((maps[nx][ny], nx, ny))
                            continue
                q.append((nx, ny))
                visited.add((nx, ny))
        if len(q) == 0:
            index = 0
            while index < len(location):
                if location[index][0].lower() in h_keys:
                    q.append((location[index][1], location[index][2]))
                    location.pop(index)
                else:
                    index += 1
    return answer


if __name__ == "__main__":
    for _ in range(int(input())):  # 테스트 케이스만큼 반복
        h, w = map(int, input().split())  # 높이, 너비
        maps = [list(input().strip()) for _ in range(h)]
        k = input()
        if k != "0":
            h_keys = set(k.strip())  # 보유하고 있는 키 리스트
        else:
            h_keys = set()

        # 테두리 검사 - 키 획득
        # 0, 마지막 행
        for i in range(w):
            if "a" <= maps[0][i] <= "z":
                h_keys.add(maps[0][i])
            if "a" <= maps[h - 1][i] <= "z":
                h_keys.add(maps[h - 1][i])
        # 0, 마지막 열
        for i in range(h):
            if "a" <= maps[i][0] <= "z":
                h_keys.add(maps[i][0])
            if "a" <= maps[i][w - 1] <= "z":
                h_keys.add(maps[i][w - 1])

        q = deque()  # 시작 가능한 위치 저장
        location = []  # 키가 없어서 이동하지 못하는 곳
        # 0, 마지막 행
        for i in range(w):
            if "A" <= maps[0][i] <= "Z":
                if maps[0][i].lower() in h_keys:
                    q.append((0, i))
                else:
                    location.append((maps[0][i], 0, i))
            elif maps[0][i] == "." or maps[0][i] == '$':
                q.append((0, i))
            if "A" <= maps[h - 1][i] <= "Z":
                if maps[h - 1][i].lower() in h_keys:
                    q.append((h - 1, i))
                else:
                    location.append((maps[h - 1][i], h - 1, i))
            elif maps[h - 1][i] == "." or maps[h - 1][i] == '$':
                q.append((h - 1, i))
        # 0, 마지막 열
        for i in range(h):
            if "A" <= maps[i][0] <= "Z":
                if maps[i][0].lower() in h_keys:
                    q.append((i, 0))
                else:
                    location.append((maps[i][0], i, 0))
            elif maps[i][0] == "." or maps[i][0] == '$':
                q.append((i, 0))
            if "A" <= maps[i][w - 1] <= "Z":
                if maps[i][w - 1].lower() in h_keys:
                    q.append((i, w - 1))
                else:
                    location.append((maps[i][w - 1], i, w - 1))
            elif maps[i][w - 1] == "." or maps[i][w - 1] == '$':
                q.append((i, w - 1))
        print(bfs(q, location))