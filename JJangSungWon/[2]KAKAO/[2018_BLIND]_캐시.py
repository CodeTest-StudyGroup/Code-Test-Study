from collections import deque


def solution(cacheSize, cities):
    if cacheSize == 0:
        return len(cities) * 5

    # cities 도시 모두 대문자로 변환
    for i in range(len(cities)):
        cities[i] = cities[i].upper()

    answer = 0
    q = deque()
    for i in range(len(cities)):
        if cities[i] in q:
            answer += 1
            q.remove(cities[i])
            q.append(cities[i])  # 가장 최신값으로 업데이트
        else:
            if len(q) < cacheSize:
                q.append(cities[i])
            elif len(q) == cacheSize:
                q.popleft()
                q.append(cities[i])

            answer += 5
    return answer


if __name__ == "__main__":
    print(solution(3, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
    # print(solution(3, ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]))
