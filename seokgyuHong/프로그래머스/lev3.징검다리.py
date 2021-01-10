def solution(stones, k):
    answer = 0
    minn = min(stones)
    maxx = max(stones)

    while (minn <= maxx):
        mid = (minn + maxx) // 2
        cur = 0
        flag = True
        cur = 0
        cnt = 0
        while (cur < len(stones) - k):
            if stones[cur] < mid:
                cnt += 1
                cur += 1
            else:
                cur += 1
                cnt = 0
            if cnt == k:
                flag = False
                break

        if flag == False:
            maxx = mid - 1
        else:
            answer = mid
            minn = mid + 1

    return answer


print(solution([2,4,5,3,2,1,4,2,5,1],3))