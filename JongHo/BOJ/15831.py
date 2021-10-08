from collections import deque

n, b, w = map(int, input().split())
stone = deque(list(input()))
road = deque()

ans = 0
white = 0
black = 0

while stone:
    if stone[0] == "W":
        white += 1
    else:
        black += 1
    road.append(stone.popleft())

    if black > b:
        while black > b:
            a = road.popleft()
            if a == "W":
                white -= 1
            else:
                black -= 1
    if white >= w and black <= b:
        ans = max(ans, white + black)

print(ans)