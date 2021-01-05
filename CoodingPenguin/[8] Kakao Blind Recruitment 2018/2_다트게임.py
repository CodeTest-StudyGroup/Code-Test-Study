import re


def solution(dartResult):
    bonus_dict = {'S':1, 'D':2, 'T':3}  # bonus 문자와 점수 대응
    
    p = re.compile('(\d+)([SDT])([*#]?)')   # 정규식으로 파싱
    terms = re.findall(p, dartResult)

    result = [] # 각 게임별 점수
    for term in terms:
        score, bonus, option = term
        score = int(score) ** bonus_dict[bonus]
        # 옵션 #인 경우 마이너스화
        if option == "#":
            result.append(-score)
        # 옵션 *인 경우 현재와 그 전 점수 2배
        elif option == "*":
            result.append(2*score)
            if len(result) > 1:
                result[-2] *= 2
        # 옵션이 없는 경우
        else:
            result.append(score)
    
    return sum(result)