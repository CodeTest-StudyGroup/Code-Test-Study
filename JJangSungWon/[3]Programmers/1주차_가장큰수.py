"""
def solution(numbers):
    numbers.sort(key=lambda x: len(str(x)))
    print(numbers)
    numbers.sort(key=lambda x: x // pow(10, len(str(x)) - 1), reverse=True)
    print(numbers)
    result = "".join(map(str, numbers))

    return result
"""


def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x * 4, reverse=True)
    result = "".join(map(str, numbers))

    if int(result) == 0 or result[0] == '0':
        return str(int(result))
    else:
        return result