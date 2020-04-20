def solution(board, moves):
    answer = 0
    basket = []

    for i in range(len(moves)):
        for j in range(len(board)):
            if board[j][moves[i]-1] == 0:
                continue
            else:
                basket.insert(0, board[j][moves[i]-1])
                board[j][moves[i]-1] = 0
                if len(basket) > 1:
                    if basket[0] == basket[1]:
                        basket.pop(0)
                        basket.pop(0)
                        answer += 2
                break

    return answer


if __name__ == "__main__":
    print(solution([[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]))
