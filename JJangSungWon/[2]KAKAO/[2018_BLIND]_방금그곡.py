def music_time(start, end):  # 음악 재생시간
    start_h, start_m = map(int, start.split(":"))
    end_h, end_m = map(int, end.split(":"))
    return (end_h * 60 + end_m) - (start_h * 60 + start_m)


def matching(data, music, play_time):
    # data, music을 '#"과 음을 붙인 형태로 만든다.
    data_list = []
    music_list = []
    if len(data) > 1:
        value = data[0]
        for i in range(1, len(data)):
            if data[i] == "#":
                value += data[i]
            else:
                data_list.append(value)
                value = data[i]
            if i == len(data) - 1:
                data_list.append(value)
    elif len(data) == 1:
        data_list = [data[0]]
    else:
        return False

    if len(music) > 1:
        value = music[0]
        for i in range(1, len(music)):
            if music[i] == "#":
                value += music[i]
            else:
                music_list.append(value)
                value = music[i]
            if i == len(music) - 1:
                music_list.append(value)
    elif len(music) == 1:
        music_list = [music[0]]
    else:
        return False

    data_set = set(data_list)
    music_set = set(music_list)

    for index in data_set:
        if index not in music_set:
            return False

    if len(data_list) > len(music):
        data_list = data_list[:len(music)]

    # music 확장
    music = []
    index = 0
    cnt = 0
    while cnt < play_time:
        if index == len(music_list):
            index = 0
        music.append(music_list[index])
        index += 1
        cnt += 1

    try:
        for i in range(len(music)):
            for j in range(i, i + len(data_list)):
                if music[j] == data_list[j - i]:
                    if j == i + len(data_list) - 1:
                        return True
                else:
                    break
    except:
        return False


def solution(m, musicinfos):
    answer = "(None)"
    max_time = -1

    for i in range(len(musicinfos)):  # 음악의 종류만큼 반복
        musicinfos[i] = str(musicinfos[i]).split(",")
        play_time = music_time(musicinfos[i][0], musicinfos[i][1])  # 재생 시간
        flag = matching(m, musicinfos[i][3], play_time)
        if answer is not None and play_time < max_time:
            continue
        elif flag:
            if max_time < play_time:
                max_time = play_time
                answer = musicinfos[i][2]

    return answer


if __name__ == "__main__":
    # print(solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
    # print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
    # print(solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
    # print(solution("CCB", ["03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"]))
    print(solution("A#", ["13:00,13:02,HAPPY,B#A#"]))
