class Node(object):  # Trie Node
    def __init__(self, key):
        self.key = key  # 현재 값
        self.remain_length = {}  # Terminal까지 남아있는 문자열의 길이
        self.children = {}  # 자식


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):

        curr_node = self.head
        remain_length = len(string)

        # 이미 있는 경우는 + 1
        if remain_length in curr_node.remain_length:
            curr_node.remain_length[remain_length] += 1
        else:
            curr_node.remain_length[remain_length] = 1

        for char in string:
            if char not in curr_node.children:  # 없으면 새로 만든다
                curr_node.children[char] = Node(char)

            curr_node = curr_node.children[char]
            remain_length -= 1  # 한 칸 진행했으니 1을 뺀다

            # 위와 똑같이 remain 진행
            if remain_length in curr_node.remain_length:
                curr_node.remain_length[remain_length] += 1
            else:
                curr_node.remain_length[remain_length] = 1

    def search_count(self, string, check_length):
        curr_node = self.head

        for char in string:
            if char in curr_node.children:
                curr_node = curr_node.children[char]
            else:
                return 0

        # ? 관련
        if check_length in curr_node.remain_length:
            return curr_node.remain_length[check_length]
        else:
            return 0


def solution(words, queries):
    t = Trie()
    inv_t = Trie()

    for word in words:
        t.insert(word)
        inv_t.insert(word[-1::-1])

    answer = []
    for i in range(len(queries)):
        query = queries[i]

        if query[0] == "?":
            query = query[-1::-1]
            chars = query.replace("?", "")  # ? 제거
            check_length = len(query) - len(chars)
            answer.append(inv_t.search_count(chars, check_length))
        else:
            chars = query.replace("?", "")  # ? 제거
            check_length = len(query) - len(chars)
            answer.append(t.search_count(chars, check_length))

    return answer


if __name__ == "__main__":
    print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
                   ["fro??", "????o", "fr???", "fro???", "pro?"]))
