def solution(n, stages):
    count = [0] * (n + 2)
    result = []

    # 각 수들의 개수 계산
    for i in range(len(stages)):
        count[stages[i]] += 1

    # 실패율 계산
    for i in range(1, n + 1):
        if count[i] + sum(count[i + 1:]) == 0:
            result.append([i, 0])
        else:
            result.append([i, count[i] / (count[i] + sum(count[i + 1:]))])  # 인덱스, 클리어하지 못한 츨레이어의 수 / 성공한 플레이어의 수

    result = sorted(result, key=lambda x: x[1], reverse=True)
    for i in range(len(result)):
        result[i] = result[i][0]

    return result