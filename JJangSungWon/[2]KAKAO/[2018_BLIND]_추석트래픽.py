def find_start_time(array):
    start, end = 0, 0
    h, m, s = array[1].split(":")
    e_integer, e_fractional = map(int, s.split("."))
    if "." in array[2]:
        s_integer, s_fractional = array[2].split(".")
        s_integer, s_fractional = int(s_integer), int(s_fractional[:-1])
    else:
        s_integer, s_fractional = int(array[2][:-1]), 0
    end = e_fractional + e_integer * 1000 + int(m) * 60000 + int(h) * 3600000
    start = end - (s_integer * 1000 + s_fractional) + 1
    return start, end


def solution(lines):
    # 공백을 기준으로 구분한다.
    for i in range(len(lines)):
        lines[i] = lines[i].split(" ")
    # 처리시간을 lines에 적용한다(시작 지점, 끝나는 지점 구분)
    # 끝나는 지점 값을 정수로 표현한다(초 * 1000, 분 * 60000, 시 * 3600000
    for i in range(len(lines)):
        start, end = find_start_time(lines[i])
        lines[i].append(start)
        lines[i].append(end)

    # 최댓값 계산
    answer = 1
    for i in range(len(lines)):
        t = lines[i][-1]
        cnt = 1
        for j in range(i + 1, len(lines)):
            if lines[j][-2] <= t + 999 or t + 999 >= lines[j][-1]:
                cnt += 1
        answer = max(answer, cnt)
    return answer


if __name__ == "__main__":
    # print(solution(["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]))
    # print(solution(["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]))
    print(solution(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"]))