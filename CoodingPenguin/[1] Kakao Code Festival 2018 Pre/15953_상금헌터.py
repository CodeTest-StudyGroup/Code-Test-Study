import sys

input = sys.stdin.readline

first = [0, 500] + [300]*2 + [200]*3 + [50]*4 + [30]*5 + [10]*6
second = [0, 512] + [256]*2 + [128]*4 + [64]*8 + [32]*16

T = int(input())
for _ in range(T):
  a, b = map(int, input().split())
  result = 0
  if a > 0 and a < len(first):
    result += first[a]
  if b > 0 and b < len(second):
    result += second[b]
  print(result*10000)
