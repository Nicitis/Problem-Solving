# 백준 14002: 가장 긴 증가하는 부분 수열 4
"""
가장 긴 증가하는 부분 수열에서 가장 긴 부분 수열을 직접 출력해주기
기존 코드에서 가장 긴 수열을 역으로 추적한다.
"""

# 입력
n = int(input())
seq = [0] + list(map(int, input().split()))

# 증가하는 부분 수열 길이 구하기
# 각 수를 마지막으로 하는 '가장 긴 증가하는 부분 수열'의 길이
max_lengths = [0] + [1 for _ in range(n)]
for i in range(1, n + 1):
  # 이전의 수를 통해 증가하는 부분 수열을 이룰 수 있는지 검사한다.
  for k in range(1, i):
    # 증가하는 수열을 이룰 수 있다면 최대 길이를 갱신한다
    if seq[k] < seq[i]:
      max_lengths[i] = max(max_lengths[i], max_lengths[k] + 1)

# 부분 수열 찾기
# 가장 긴 증가 부분 수열의 마지막 원소를 찾는다.
max_length = 0
last_idx = -1
for i in range(1, n + 1):
  if max_length < max_lengths[i]:
    last_idx = i
    max_length = max_lengths[i]

# 부분 수열을 역순으로 탐색
count = max_length - 1
asc_queue = [seq[last_idx]]
for i in range(last_idx - 1, 0, -1):
  if max_lengths[i] == count and seq[i] < asc_queue[-1]:
    asc_queue.append(seq[i])
    count -= 1

asc_queue.reverse() # 수열이 역순이므로 뒤집음

# 출력
print(max_length)
for elem in asc_queue:
  print(elem, end=' ')