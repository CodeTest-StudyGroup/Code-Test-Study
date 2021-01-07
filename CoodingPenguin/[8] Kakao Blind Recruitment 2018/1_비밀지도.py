def solution(n, arr1, arr2):
    result = []
    arr = [x|y for x, y in zip(arr1, arr2)]
    for item in arr:
        row = "{:b}".format(item).zfill(n)
        row = row.replace("1", "#").replace("0", " ")
        result.append(row)
    return result