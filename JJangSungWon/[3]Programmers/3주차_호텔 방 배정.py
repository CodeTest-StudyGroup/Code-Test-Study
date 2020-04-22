import sys

sys.setrecursionlimit(10 ** 6)


def find_empty(n, result):
    if n not in result:
        result[n] = n + 1
        return n

    # 재귀 함수로 빈 방 찾기
    empty_room = find_empty(result[n], result)
    result[n] = empty_room + 1

    return empty_room


def solution(k, room_number):
    result = {}
    answer = []

    for i in range(len(room_number)):
        answer.append(find_empty(room_number[i], result))

    return answer


if __name__ == "__main__":
    print(solution(10, [1, 3, 4, 1, 3, 1]))
