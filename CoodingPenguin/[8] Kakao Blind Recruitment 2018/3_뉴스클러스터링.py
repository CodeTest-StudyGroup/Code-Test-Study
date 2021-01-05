from collections import Counter


def gen_counter(title):
    title = title.lower()
    t_set = []
    for i in range(len(title)-1):
        item = title[i:i+2]
        if item.isalpha():
            t_set.append(item)
    return Counter(t_set)


def solution(str1, str2):
    NUM = 65536
    counter1, counter2 = gen_counter(str1), gen_counter(str2)
    inter = sum((counter1 & counter2).values())
    union = sum((counter1 | counter2).values())
    if not inter and not union:
        return NUM
    return int(inter/union*NUM)