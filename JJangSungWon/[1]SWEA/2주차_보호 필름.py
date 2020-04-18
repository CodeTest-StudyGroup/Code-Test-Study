import itertools
import copy


def check(m):
    temp = []
    for i in range(W):
        cnt, max_cnt = 1, 0
        val = data[0][i]
        for j in range(1, D):
            if max_cnt >= K:
                break
            if data[j][i] != val:
                max_cnt = max(max_cnt, cnt)
                cnt = 1
                val = data[j][i]
            else:
                cnt += 1
        max_cnt = max(max_cnt, cnt)
        temp.append(max_cnt)

    flag = 1
    for i in range(W):
        if temp[i] < K:
            return 0

    if flag == 1:
        return 1


if __name__ == "__main__":

    T = int(input())

    for tc in range(1, T + 1):
        D, W, K = map(int, input().split())
        data = []
        pre_value, post_value = 0, 0
        print_check = 0
        for _ in range(D):
            data.append(list(map(int, input().split())))

        # 약품을 넣지 않고 통과할 수 있는지 확인
        if check(0) == 1:
            print_check = 1
            print("#{0} {1}".format(tc, 0))
        else:
            original = [i for i in range(1, D + 1)]  # 후보 줄
            original_2 = [0, 1]
            flag = 1
            copy_data = copy.deepcopy(data)

            for m in range(1, K + 1):  # 1개부터 K개 까지 수리 가정
                if flag == 0:
                    break
                if m != 1:
                    temp = list(itertools.combinations(original, m))
                    temp_2 = list(itertools.product(original_2, repeat=m))

                    for n in range(len(temp)):
                        if flag == 0:
                            break
                        for p in range(2):
                            if flag == 0:
                                break
                            for k in range(len(temp[n])):
                                temp_3 = [original_2[p]] * W
                                data[temp[n][k] - 1] = temp_3

                            if check(m) == 1:
                                pre_value = m
                                flag = 0
                                break
                            data = copy.deepcopy(copy_data)
                else:
                    for n in range(len(original)):
                        if flag == 0:
                            break

                        for k in range(len(original_2)):
                            if flag == 0:
                                break

                            temp_3 = [original_2[k]] * W
                            temp_4 = data[original[n] - 1]
                            data[original[n] - 1] = temp_3

                            if check(m) == 1:
                                pre_value = m
                                flag = 0
                                break

                            data[original[n] - 1] = temp_4

        if print_check == 0:
            original = [i for i in range(1, D + 1)]  # 후보 줄
            original_2 = [0, 1]
            flag = 1
            data = copy.deepcopy(copy_data)

            for m in range(1, 5):  # 1개부터 K개 까지 수리 가정
                if flag == 0:
                    break
                if m != 1:
                    temp = list(itertools.combinations(original, m))
                    temp_2 = list(itertools.product(original_2, repeat=m))

                    for n in range(len(temp)):
                        if flag == 0:
                            break
                        for p in range(len(temp_2)):
                            if flag == 0:
                                break
                            for k in range(len(temp[n])):
                                temp_3 = [temp_2[p][k]] * W
                                data[temp[n][k] - 1] = temp_3

                            if check(m) == 1:
                                print("#{0} {1}".format(tc, m))
                                flag = 0
                                break
                            data = copy.deepcopy(copy_data)
                else:
                    for n in range(len(original)):
                        if flag == 0:
                            break

                        for k in range(len(original_2)):
                            if flag == 0:
                                break

                            temp_3 = [original_2[k]] * W
                            temp_4 = data[original[n] - 1]
                            data[original[n] - 1] = temp_3

                            if check(m) == 1:
                                print("#{0} {1}".format(tc, m))
                                flag = 0
                                break

                            data[original[n] - 1] = temp_4

            if flag == 1:
                print("#{0} {1}".format(tc, pre_value))