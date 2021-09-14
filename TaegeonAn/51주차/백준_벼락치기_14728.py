N, T = map(int, input().split())

chapter_time, chapter_score = [0], [0]

for _ in range(N):
    K, S = map(int, input().split())
    chapter_time.append(K)
    chapter_score.append(S)

dp_score = [[0 for _ in range(T+1)] for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(1, T+1):
        if j >= chapter_time[i]:
            dp_score[i][j] = max(dp_score[i-1][j], dp_score[i-1][j-chapter_time[i]]+chapter_score[i])
        else:
            dp_score[i][j] = dp_score[i-1][j]

print(dp_score[N][T])
