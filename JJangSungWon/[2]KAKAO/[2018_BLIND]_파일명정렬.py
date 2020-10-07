def find_head(array):  # HEAD 추출
    index = -1
    for i in range(len(array)):
        if "0" <= array[i] <= "9":
            index = i
            break
    return array[:index], index


def find_number(array):  # NUMBER 추출
    index = -1
    try:
        for i in range(5):
            if "0" <= array[i] <= "9":
                index = i
            else:
                break
    except:
        pass
    return array[:index + 1]


def solution(files):
    answer = []
    head_number_files = []
    for i in range(len(files)):
        head, index = find_head(files[i])
        number = find_number(files[i][index:])
        head_number_files.append((head.upper(), int(number), i))  # head, number, index 값

    # head, number 순으로 오름차순 정렬
    head_number_files.sort(key=lambda x: (x[0], x[1]))

    for i in range(len(head_number_files)):
        answer.append(files[head_number_files[i][2]])
    return answer


if __name__ == "__main__":
    print(solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))
    # print(solution(["abc123", "foo9.txt", "foo010bar020.zip", "F-15"]))