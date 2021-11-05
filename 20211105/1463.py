# 백준 1463: 1로 만들기(python3)
n = int(input())
dp = [0, 0]
for i in range(2, n + 1):
    dp.append(dp[i - 1] + 1)
    if i % 3 == 0 and i >= 3:
        dp[i] = min(dp[i], dp[int(i//3)] + 1)
    if i % 2 == 0 and i >= 2:
        dp[i] = min(dp[i], dp[int(i//2)] + 1)

print(dp[n])