#14501 퇴사

#아 별로 안어려운 dfs 문제인 줄 알았는데 생각보다 끝 처리가 어려웠다..
#로직은 그렇게 어렵지 않은데 끝 부분 처리가 까다로워서 시간이 꽤 오래 걸렸따...

#MAX를 음수 이상한 값으로 잡아서 만약에 모든 작업이 불가능하면 0을 출력해야하는데 음수값을 출력한다!! 예외처리 필수
MAX = 0

def dfs(start, plus, sum):
    global MAX
    if start > N: return

    if start + arr[start][0] >N:
        return

    sum += plus
    MAX = max(MAX,sum)

    for i in range(start+arr[start][0],N):
        dfs(i,arr[i][1], sum)
        


N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
visited = [0 for _ in range(N)]


for i in range(0,N):
    dfs(i,arr[i][1],0)

print(MAX)
