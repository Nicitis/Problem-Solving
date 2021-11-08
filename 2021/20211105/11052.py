# 백준 11052: 카드 구매하기
N = int(input())
cost = list(map(int, input().split()))
cost.insert(0, 0)

dp = [0]
for i in range(1, N + 1):
  dp.append(max(dp[i - x] + cost[x] for x in range(1, i + 1)))
  # i장 구매 금액 = max([i-x장 구매 금액] + x장 구매 금액)

print(dp[N])