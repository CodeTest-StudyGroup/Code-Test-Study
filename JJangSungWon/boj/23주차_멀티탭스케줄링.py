from collections import defaultdict, deque
import sys


if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    array = list(map(int, sys.stdin.readline().split()))

    # 전기 용품의 종류에 따른 인덱스 저장 딕셔너리 (name_dict)
    name_dict = defaultdict(deque)
    for i in range(len(array)):
        name_dict[array[i]].append(i)

    # 멀티탭 구멍의 개수만큼 큐에 삽입
    q = deque()
    cnt = 0
    index = 0
    while cnt < n:
        if array[index] not in q:
            q.append(array[index])  # 삽입
            name_dict[array[index]].popleft()  # 인덱스 삭제
            cnt += 1
        else:
            name_dict[array[index]].popleft()
        index += 1

    # 현재 멀티탭에 꽂아진 전기용품 중 가장 뒤늦게 다시 등장하는 전기용품 찾아서 바꾼다
    answer = 0
    result = set()
    for i in range(index, k):
        if array[i] in q:  # 이미 꽂혀있는 경우
            name_dict[array[i]].popleft()
            continue
        else:
            index, value = -1, None
            for j in range(n):
                if len(name_dict[q[j]]) == 0:
                    index, value = -1, q[j]
                    break
                if index < name_dict[q[j]][0]:
                    index, value = name_dict[q[j]][0], q[j]
            answer += 1
            q.remove(value)
            q.append(array[i])
            if len(name_dict[array[i]]) != 0:
                name_dict[array[i]].popleft()

    print(answer)