def solution(genres, plays):
    answer = []
    genre = list(set(genres))
    arr = dict()
    public = [[] for _ in range(len(genre))]
        
    for i in genre:
        arr[i] = 0
    # 각 장르마다 총 플레이 횟수 구함.
    for idx, i in enumerate(genres):
        arr[i] += plays[idx]
    # public리스트에 현재 장르의 총 플레이횟수, 현재 노래 플레이횟수, 고유번호를 저장.
    for idx, i in enumerate(zip(genres, plays)):
        public[genre.index(i[0])].append([arr[i[0]], i[1], idx])
    # 주어진 조건대로 정렬한다.
    for i in range(len(public)):
        public[i].sort(reverse = True, key = lambda x : (x[1], -x[2]))
        if len(public[i]) > 2:
            public[i] = public[i][:2]
    public.sort(reverse=True, key=lambda x : x[0])

    for i in public:
        for j in i:
            answer.append(j[2])
    
    return answer