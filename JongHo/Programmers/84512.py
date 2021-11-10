from itertools import product

def solution(word):
    words = ["A", "E", "I", "O", "U"]
    
    all_words = []
    
    for i in range(1, 6):
        for j in product(words, repeat=i):
            all_words.append("".join(j))
    all_words.sort()
    
    return all_words.index(word) + 1