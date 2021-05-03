"""
생태학
https://www.acmicpc.net/problem/4358
"""
import sys

plant_dict = dict()
total_len = 0
# while True:
for line in sys.stdin:
    tmp = line.rstrip()
    tmp = input()
    if not tmp:
        break
    total_len += 1
    plant_dict[tmp] = plant_dict.get(tmp,0) + 1

plant_dict = sorted(plant_dict.items(), key= lambda x : x[0])
# print(plant_dict)
for name, cnt in plant_dict:
    print(f"{name} {(cnt*100) / total_len:.4f}")
