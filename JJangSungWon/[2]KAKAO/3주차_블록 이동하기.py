import sys
import copy

answer = sys.maxsize


def bfs(board, start):
    queue = [start]
    visited = [start]
    cnt = 0

    while queue:
        queue_len = len(queue)
        temp = []
        while queue_len:
            sub_queue = queue.pop()
            back = sub_queue[0]
            front = sub_queue[1]

            if front[0] == len(board) - 1 and front[1] == len(board) - 1:
                return cnt
            else:
                if back[0] == front[0]:  # 가로 상황
                    # 상
                    if back[0] - 1 >= 0 and board[back[0] - 1][back[1]] == 0 and board[front[0] - 1][front[1]] == 0:
                        if ([back[0] - 1, back[1]], [front[0] - 1, front[1]]) not in visited:
                            temp.append(([back[0] - 1, back[1]], [front[0] - 1, front[1]]))
                            visited.append(([back[0] - 1, back[1]], [front[0] - 1, front[1]]))

                    if back[0] + 1 < len(board) and board[back[0] + 1][back[1]] == 0 and board[front[0] + 1][front[1]] == 0:  # 하
                        if ([back[0] + 1, back[1]], [front[0] + 1, front[1]]) not in visited:
                            temp.append(([back[0] + 1, back[1]], [front[0] + 1, front[1]]))
                            visited.append(([back[0] + 1, back[1]], [front[0] + 1, front[1]]))

                    if back[1] - 1 >= 0 and board[back[0]][back[1] - 1] == 0:  # 좌
                        if ([back[0], back[1] - 1]) not in visited:
                            temp.append(([back[0], back[1] - 1], back))
                            visited.append(([back[0], back[1] - 1], back))

                    if front[1] + 1 < len(board) and board[front[0]][front[1] + 1] == 0:  # 우
                        if (front, [front[0], front[1] + 1]) not in visited:
                            temp.append((front, [front[0], front[1] + 1]))
                            visited.append((front, [front[0], front[1] + 1]))

                    # 상 우, 상 좌
                    if back[0] - 1 >= 0 and board[back[0] - 1][back[1]] == 0 and board[front[0] - 1][front[1]] == 0:
                        if ([front[0] - 1, front[1]], front) not in visited:
                            temp.append(([front[0] - 1, front[1]], front))
                            visited.append(([front[0] - 1, front[1]], front))
                        if ([back[0] - 1, back[1]], back) not in visited:
                            temp.append(([back[0] - 1, back[1]], back))
                            visited.append(([back[0] - 1, back[1]], back))

                    # 하 우, 하 좌
                    if back[0] + 1 < len(board) and board[back[0] + 1][back[1]] == 0 and board[front[0] + 1][front[1]] == 0:
                        if (front, [front[0] + 1, front[1]]) not in visited:
                            temp.append((front, [front[0] + 1, front[1]]))
                            visited.append((front, [front[0] + 1, front[1]]))
                        if (back, [back[0] + 1, back[1]]) not in visited:
                            temp.append((back, [back[0] + 1, back[1]]))
                            visited.append((back, [back[0] + 1, back[1]]))

                elif back[0] != front[0]:  # 세로 상황
                    if back[0] - 1 >= 0 and board[back[0] - 1][back[1]] == 0:  # 상
                        if ([back[0] - 1, back[1]], back) not in visited:
                            temp.append(([back[0] - 1, back[1]], back))
                            visited.append(([back[0] - 1, back[1]], back))

                    if front[0] + 1 < len(board) and board[front[0] + 1][front[1]] == 0:  # 하
                        if (front, [front[0] + 1, front[1]]) not in visited:
                            temp.append((front, [front[0] + 1, front[1]]))
                            visited.append((front, [front[0] + 1, front[1]]))

                    if back[1] - 1 >= 0 and board[back[0]][back[1] - 1] == 0 and board[front[0]][front[1] - 1] == 0:
                        if ([back[0], back[1] - 1], [front[0], front[1] - 1]) not in visited:
                            temp.append(([back[0], back[1] - 1], [front[0], front[1] - 1]))
                            visited.append(([back[0], back[1] - 1], [front[0], front[1] - 1]))

                    if back[1] + 1 < len(board) and board[back[0]][back[1] + 1] == 0 and board[front[0]][front[1] + 1] == 0:
                        if ([back[0], back[1] + 1], [front[0], front[1] + 1]) not in visited:
                            temp.append(([back[0], back[1] + 1], [front[0], front[1] + 1]))
                            visited.append(([back[0], back[1] + 1], [front[0], front[1] + 1]))


                        # (상, 우) (하, 우) 대각선
                    if back[1] + 1 < len(board) and board[back[0]][back[1] + 1] == 0 and board[front[0]][front[1] + 1] == 0:
                        if (front, [front[0], front[1] + 1]) not in visited:
                            temp.append((front, [front[0], front[1] + 1]))
                            visited.append((front, [front[0], front[1] + 1]))
                        if (back, [back[0], back[1] + 1]) not in visited:
                            temp.append((back, [back[0], back[1] + 1]))
                            visited.append((back, [back[0], back[1] + 1]))

                        # (상, 좌) (하, 좌) 대각선
                    if back[1] - 1 >= 0 and board[back[0]][back[1] - 1] == 0 and board[front[0]][front[1] - 1] == 0:
                        if ([front[0], front[1] - 1], front) not in visited:
                            temp.append(([front[0], front[1] - 1], front))
                            visited.append(([front[0], front[1] - 1], front))
                        if ([back[0], back[1] - 1], back) not in visited:
                            temp.append(([back[0], back[1] - 1], back))
                            visited.append(([back[0], back[1] - 1], back))

            queue_len -= 1
        queue = copy.deepcopy(temp)
        cnt += 1


def solution(board):
    return bfs(board, ([0, 0], [0, 1]))


if __name__ == "__main__":
    print(solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]))
"""
 dfs로 처음에 구현하였지만 예시만 맞고 대부분은 틀렸다.
 최단거리로 가는 문제는 bfs로 구현하는 것이 예외 상황을 체크하기가 좋은 것 같다.
import sys

answer = sys.maxsize


def dfs(board, back, front, cnt, visited):
    global answer
    if front[0] == len(board) - 1 and front[1] == len(board) - 1:
        answer = min(answer, cnt)
        return

    if cnt > answer:
        return

    if back[0] == front[0]:  # 가로 상황
        # 좌
        if back[1] - 1 >= 0 and board[back[0]][back[1] - 1] == 0 and [back[0], back[1] - 1] not in visited:
            visited.append([back[0], back[1] - 1])
            dfs(board, [back[0], back[1] - 1], back, cnt + 1, visited)
            visited.remove([back[0], back[1] - 1])
        # 우
        if front[1] + 1 < len(board) and board[front[0]][front[1] + 1] == 0 and [front[0], front[1] + 1] not in visited:
            visited.append([front[0], front[1] + 1])
            dfs(board, front, [front[0], front[1] + 1], cnt + 1, visited)
            visited.remove([front[0], front[1] + 1])
        # (상, 우), (상, 좌) 대각선
        if back[0] - 1 >= 0 and board[back[0] - 1][back[1]] == 0 and board[front[0] - 1][front[1]] == 0:
            if [front[0] - 1, front[1]] not in visited:
                visited.append([front[0] - 1, front[1]])
                dfs(board, [front[0] - 1, front[1]], front, cnt + 1, visited)  # 상 우
                visited.remove([front[0] - 1, front[1]])
            if [back[0] - 1, back[1]] not in visited:
                visited.append([back[0] - 1, back[1]])
                dfs(board, [back[0] - 1, back[1]], back, cnt + 1, visited)  # 상 좌
                visited.remove([back[0] - 1, back[1]])

        # (하, 우), (하, 좌) 대각선
        if back[0] + 1 < len(board) and board[back[0] + 1][back[1]] == 0 and board[front[0] + 1][front[1]] == 0:
            if [front[0] + 1, front[1]] not in visited:
                visited.append([front[0] + 1, front[1]])
                dfs(board, front, [front[0] + 1, front[1]], cnt + 1, visited)  # 하 우
                visited.remove([front[0] + 1, front[1]])
            if [back[0] + 1, back[1]] not in visited:
                visited.append([back[0] + 1, back[1]])
                dfs(board, back, [back[0] + 1, back[1]], cnt + 1, visited)  # 하 좌
                visited.remove([back[0] + 1, back[1]])

    if back[0] != front[0]:  # 세로 상황
        # 상
        if back[0] - 1 >= 0 and board[back[0] - 1][back[1]] == 0 and [back[0] - 1, back[1]] not in visited:
            visited.append([back[0] - 1, back[1]])
            dfs(board, [back[0] - 1, back[1]], back, cnt + 1, visited)
            visited.remove([back[0] - 1, back[1]])
        # 하
        if front[0] + 1 < len(board) and board[front[0] + 1][front[1]] == 0 and [front[0] + 1, front[1]] not in visited:
            visited.append([front[0] + 1, front[1]])
            dfs(board, front, [front[0] + 1, front[1]], cnt + 1, visited)
            visited.remove([front[0] + 1, front[1]])
        # (상, 우) (하, 우) 대각선
        if back[1] + 1 < len(board) and board[back[0]][back[1] + 1] == 0 and board[front[0]][front[1] + 1] == 0:
            if [front[0], front[1] + 1] not in visited:
                visited.append([front[0], front[1] + 1])
                dfs(board, front, [front[0], front[1] + 1], cnt + 1, visited)
                visited.remove([front[0], front[1] + 1])
            if [back[0], back[1] + 1] not in visited:
                visited.append([back[0], back[1] + 1])
                dfs(board, back, [back[0], back[1] + 1], cnt + 1, visited)
                visited.remove([back[0], back[1] + 1])

        # (상, 좌) (하, 좌) 대각선
        if back[1] - 1 >= 0 and board[back[0]][back[1] - 1] == 0 and board[front[0]][front[1] - 1] == 0:
            if [front[0], front[1] - 1] not in visited:
                visited.append([front[0], front[1] - 1])
                dfs(board, [front[0], front[1] - 1], front, cnt + 1, visited)
                visited.remove([front[0], front[1] - 1])
            if [back[0], back[1] - 1] not in visited:
                visited.append([back[0], back[1] - 1])
                dfs(board, [back[0], back[1] - 1], back, cnt + 1, visited)
                visited.remove([back[0], back[1] - 1])


def solution(board):
    dfs(board, [0, 0], [0, 1], 0, [[0, 0], [0, 1]])
    return answer


if __name__ == "__main__":
    print(solution([[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]))
"""
