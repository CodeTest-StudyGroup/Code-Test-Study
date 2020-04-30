import sys
answer = sys.maxsize


def dif_word_count(arr1, arr2):  # 단어 갯수 차이 판단
    count = 0
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            count += 1

    if count == 1:
        return True
    else:
        return False


def dfs(b, t, words, cnt, visited):
    global answer
    if b == t:
        answer = min(answer, cnt)
        return

    if cnt > answer:
        return

    for i in range(len(words)):
        if dif_word_count(b, words[i]) and i not in visited:
            visited.append(i)
            dfs(words[i], t, words, cnt + 1, visited)
            visited.pop()


def solution(begin, target, words):
    if target not in words:  # words에 target이 없는 경우
        return 0
    else:
        dfs(begin, target, words, 0, [])
        return answer


if __name__ == "__main__":
    print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
