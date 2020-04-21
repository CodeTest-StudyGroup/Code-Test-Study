#크레인 인형뽑기

def solution(board, moves):
    answer = 0
    stack = list()
    for move in moves:
        for row in range(0,len(board)):
            if board[row][move-1] != 0:
                stack.append(board[row][move-1])
                board[row][move-1] = 0
                break
        if len(stack) >= 2 and stack[-1] == stack[-2]:
            answer += 1
            stack = stack[:-2]
    
    return answer*2

if __name__ == "__main__":
    board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
    moves = [1,5,3,5,1,2,1,4]

    print(solution(board,moves))