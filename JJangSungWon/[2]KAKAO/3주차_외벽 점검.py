"""
    전체적인 아이디어는 비슷했지만, 반례를 찾기 못하고 70 ~ 90의 정확도만 나와서 결국 다른 사람의 풀이를 참고하였다.
    *2를 통해서 시계, 반시계 방향을 해결하는 게 제일 핵심이었다고 생각한다.
"""


import itertools


def solution(n, weak, dist):
    weak_length = len(weak)
    for i in range(weak_length):
        weak.append(weak[i] + n)

    answer = len(dist) + 1
    for i in range(weak_length):

        start_point = [weak[j] for j in range(i, i + weak_length)]

        # 순서
        candidates = list(itertools.permutations(dist, len(dist)))

        # 탐색
        for order in candidates:
            friend_idx, friend_count = 0, 1
            possible_check_length = start_point[0] + order[friend_idx]

            for idx in range(weak_length):

                if start_point[idx] > possible_check_length:
                    # 다음 친구 투입
                    friend_count += 1
                    # 더 이상 투입할 친구가 없는 경우 break
                    if friend_count > len(order):
                        break
                    # 다음 친구 투입, 친구가 확인할 수 있는 최대 거리 업데이트
                    friend_idx += 1
                    possible_check_length = order[friend_idx] + start_point[idx]
            # 투입할 친구 최솟값 업데이트
            answer = min(answer, friend_count)

    if answer > len(dist):
        return -1

    return answer


if __name__ == "__main__":
    print(solution(12, [1, 5, 6, 10], [1, 2, 3, 4]))


"""
1% 부족한 코드...
import copy
import sys


def solution(n, weak, dist):
    copy_distance = copy.deepcopy(dist)

    min_val = sys.maxsize
    for i in range(len(weak)):  # 각 위치를 시작점으로 둔다
        dist = copy.deepcopy(copy_distance)
        d = weak[i:]
        for j in range(i):
            d.append(weak[j] + n)

        cnt = 1
        temp, flag = 0, 1
        index = 0
        for j in range(len(d) - 1):
            if len(dist) > 0 and d[j + 1] - d[index] <= max(dist):
                temp = d[j + 1] - d[index]
            else:
                cnt += 1
                temp = 0
                index = j + 1
                if len(dist) == 0:
                    flag = 0
                    break
                dist.remove(max(dist))
        if flag:
            min_val = min(min_val, cnt)

    if min_val == sys.maxsize:
        return -1
    elif min_val == 1:
        return 1
    else:
        return min_val
"""