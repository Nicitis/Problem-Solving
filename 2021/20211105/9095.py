# 백준 9095: 1, 2, 3 더하기(python3)
# 1 => 1, 2 => 2(1+1, 2), 3 => 4(1+1+1,1+2,2+1,3)
# underscore: https://mingrammer.com/underscore-in-python/
t = int(input())
dp = [0,1,2,4]
for i in range(4, 12):
  dp.append(dp[i-3]+dp[i-2]+dp[i-1])

for _ in range(t):
  n = int(input())
  print(dp[n])