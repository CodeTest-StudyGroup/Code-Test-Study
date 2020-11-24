input=__import__('sys').stdin.readline
n=int(input().rstrip());data=[]
for _ in range(n):
    data.append(list(map(str,input().rstrip())))
mydic={}
for word in data:
    for i in range(len(word)):
        if word[i] not in mydic: mydic[word[i]]=pow(10,len(word)-1-i)
        else: mydic[word[i]]+=pow(10,len(word)-1-i)
result=sorted(mydic.items(),key=lambda x:x[1],reverse=True)
sumValue=0;alpha=9
for item in result:
    sumValue+=alpha*item[1];alpha-=1
print(sumValue)