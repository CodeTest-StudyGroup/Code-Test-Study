import heapq

if __name__ == "__main__":
    n = int(input())  # 사람 수
    edge = [list(map(int, input().split())) for _ in range(n)]
    line = int(input())

    # 오른쪽 끝 점을 기준으로 오름차순 정렬
    for i in range(n):
        if edge[i][1] - edge[i][0] <= line:
            if edge[i][0] > edge[i][1]:
                edge[i][0], edge[i][1] = edge[i][1], edge[i][0]
    edge.sort(key=lambda x: x[1])

    q = []
    answer = 0
    for i in range(n):
        if edge[i][1] - edge[i][0] <= line:  # 선분에 포함될 수 있는지 파악
            while q and q[0][0] < edge[i][1] - line:  # 선분에 포함되지 않는 것은 제외
                heapq.heappop(q)
            heapq.heappush(q, (edge[i][0], edge[i][1]))  # 현재 선분 추가
            answer = max(answer, len(q))  # 최댓값 업데이트

    # 출력
    print(answer)
