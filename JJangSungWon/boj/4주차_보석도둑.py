import heapq
import sys


if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())  # 보석, 가방의 개수
    data = []  # 보석 정보
    for _ in range(n):
        m, v = map(int, sys.stdin.readline().split())
        heapq.heappush(data, (m, v))
    bag = [int(input()) for _ in range(k)]  # 가방 정보
    # 가방 오름차순 정렬
    bag.sort()

    answer = 0
    temp = []
    # 가장 작은 가방부터 하나씩 대입한다.
    for i in range(len(bag)):
        # 가방에 담을 수 있는 보석 중에 무게가 가장 큰 것을 찾는다.
        while data and data[0][0] <= bag[i]:
            m, v = heapq.heappop(data)
            if m <= bag[i]:
                heapq.heappush(temp, (-v, m))  # 가격을 기준값으로 설정
            else:
                break

        if len(temp) != 0:
            answer += -temp[0][0]
            heapq.heappop(temp)
    print(answer)