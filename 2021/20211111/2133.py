# 백준 2133: 타일 채우기(Python3)
# f(N): 3xN 크기의 벽을 타일로 채우는 경우의 수
# f(n) = f(n-1)*f(1) + 2 * SumOfF
# SumOfF = f(n-2) + f(n-3) + ... + f(1) + 1
# (N이 짝수일 때, n = N//2)
# f(N) = 0 (N이 홀수일 때)

n = int(input())
dp = [0, 3]
ans = 0

if n % 2 == 1:
  ans = 0
else:
  sum_dp = 1;
  for i in range(2, n//2 + 1):
    dp.append(dp[i-1] * dp[1] + 2 * sum_dp)
    sum_dp += dp[i-1]
  ans = dp[n//2]

print(ans)