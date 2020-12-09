from collections import deque


if __name__ == "__main__":
    n = int(input())
    array = [int(input()) for _ in range(n)]

    # 오름차순 정렬
    array.sort()
    q = deque(array)

    # 1보다 큰 양수 저장
    positive = []
    while q:
        num = q.pop()
        if num > 1:
            positive.append(num)
        else:
            q.append(num)
            break

    # 0이하 수 저장
    negative = []
    while q:
        num = q.popleft()
        if num <= 0:
            negative.append(num)
        else:
            q.insert(0, num)
            break

    answer = 0
    # negative 2개씩 묶어서 더하기
    for i in range(0, len(negative), 2):
        if i + 1 < len(negative):
            answer += negative[i] * negative[i + 1]
        else:
            answer += negative[i]

    # positive 2개씩 묶어서 더하기
    for i in range(0, len(positive), 2):
        if i + 1 < len(positive):
            answer += positive[i] * positive[i + 1]
        else:
            answer += positive[i]

    # 남은 수 그냥 더하기
    while q:
        num = q.pop()
        answer += num

    print(answer)