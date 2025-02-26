import math

a, b, v = map(int, input().split())

k = (v-a)/(a-b) + 1
print(max(1, math.ceil(k)))