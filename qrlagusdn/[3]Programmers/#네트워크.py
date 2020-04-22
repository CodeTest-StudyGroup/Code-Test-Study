#네트워크

def bfs(start,idx,n,computers,visited):
    queue = list()
    queue.append(start)

    while queue:
        pos = queue.pop(0)
        visited[pos] = idx
        for i in range(0,n):
            if visited[i] == 0 and computers[pos][i] == 1:
                queue.append(i)
                visited[i] = idx
            
def solution(n, computers):
    answer = 0
    idx = 1
    visited = [0]*n
    for i in range(0,n):
        if visited[i] != 0:
            continue
        bfs(i,idx,n,computers,visited)
        idx += 1
    return idx

if __name__ == "__main__":
    computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
    n = 3
    print(solution(n,computers))