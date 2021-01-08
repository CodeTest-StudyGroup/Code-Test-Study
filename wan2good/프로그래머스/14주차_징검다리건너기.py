def solution(stones,k):
    l,r=0,max(stones)
    ans=0
    while l<=r:
        flag=True;cnt=0
        mid=(l+r)//2
        for stone in stones:
            if stone-mid<=0: 
                cnt+=1
                if cnt>=k: flag=False;break
            else:
                cnt=0
        if not flag: r=mid-1
        else: l=mid+1

    return l

stones=[2,4,5,3,2,1,4,2,5,1];k=3
print(solution(stones,k))