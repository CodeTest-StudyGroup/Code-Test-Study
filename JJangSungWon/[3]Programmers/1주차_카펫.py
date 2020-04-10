def solution(brown, red):
    total = brown + red
    
    for i in range(1, total + 1):
        if total % i == 0:
            if i >= total // i:
                width, height = i, total // i
                border = total - (width - 2) * (height - 2)
                if border == brown:
                    answer=[width, height]
                    return answer