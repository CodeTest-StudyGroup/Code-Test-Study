if __name__ == "__main__":
    n = int(input())
    x, y = map(int, input().split())
    result = 0

    for _ in range(n - 1):
        temp_x, temp_y = map(int, input().split())

        if x <= temp_y <= y:  # 포함
            continue
        elif x <= temp_x <= y and not x <= temp_y <= y:  # y 연장
            y = temp_y
        else:  # 새로운 선분
            result += y - x
            x, y = temp_x, temp_y

    print(result + (y - x))