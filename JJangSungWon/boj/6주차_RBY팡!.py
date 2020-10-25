import sys


def solve():
    n = int(sys.stdin.readline().rstrip())
    ball = [0] + [int(sys.stdin.readline().rstrip()) for _ in range(n)] + [-1]

    answer = n
    for color in range(1, 4):
        for i in range(1, n + 1):
            if ball[i] == color:
                continue
            top = i + 1
            bottom = i - 1

            # i를 기준으로 오른쪽 탐색
            while ball[top] == color:
                top += 1
            # i를 기준으로 왼쪽 탐색
            while ball[bottom] == color:
                bottom -= 1

            if top - bottom - 1 >= 4:  # 동일한 색의 공이 4개 이상 연속된 상황
                cnt = top - bottom - 1  # 연속된 공의 개수
                while ball[top] == ball[bottom]:
                    sub_top = top
                    sub_bottom = bottom
                    next_color = ball[top]  # 일치해야하는 공의 색

                    # i를 기준으로 오른쪽 탐색
                    while ball[sub_top] == next_color:
                        sub_top += 1
                    # i를 기준으로 왼쪽 탐색
                    while ball[sub_bottom] == next_color:
                        sub_bottom -= 1

                    t = sub_top - top + bottom - sub_bottom

                    if t < 4:
                        break
                    else:
                        cnt += t
                        top = sub_top
                        bottom = sub_bottom

                answer = min(answer, n - cnt)
    return answer


if __name__ == "__main__":
    print(solve())