# 백준 11055: 가장 큰 증가 부분 수열
n = int(input())
seq = [0] + list(map(int, input().split()))
sums_of_seq = [0, seq[1]]

for i in range(2, n+1):
  # 자신보다 작고 최대인 수를 찾음
  maxSum = 0
  for j in range(1, i):
    if seq[j] < seq[i] and maxSum < sums_of_seq[j]:
      maxSum = sums_of_seq[j]
  sums_of_seq.append(maxSum + seq[i])

print(max(sums_of_seq))