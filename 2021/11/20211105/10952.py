# 백준 10952: A + B - 5
while(True):
  a = list(map(int, input().split()))
  if a[0] == 0 and a[1] == 0:
    break
  print(sum(a))
