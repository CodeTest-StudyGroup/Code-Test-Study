BLANK = "_"

def remove_blocks(b, m, n):
    block_set = set() # 지울 블록의 위치

    for i in range(1, n):
        for j in range(1, m):
            # 빈칸이 아니고 4개가 같은 블록이라면
            # block_set에 해당 블록들의 위치를 추가
            if b[i][j] == b[i-1][j-1] == b[i-1][j] == b[i][j-1] != BLANK:
                block_set |= set([(i, j), (i-1, j-1), (i-1, j), (i, j-1)])

    # block_set에 저장된 위치의 블록을 빈칸으로 표시
    for i, j in block_set:
        b[i][j] = BLANK 

    for i, row in enumerate(b):
        # 빈 블록 위로 위의 블록이 내려오게 함
        empty = [BLANK] * row.count(BLANK)
        b[i] = empty + [block for block in row if block != BLANK]

    # 지운 블록 수 반환
    return len(block_set)
     
def solution(m, n, board):
    count = 0   # 제거한 블록의 수
    # traverse해서 col이 row가 되게 한다
    b = list(map(list,zip(*board))) 
    while True:
        blocks = remove_blocks(b, m, n)
        if not blocks:
          return count
        count += blocks