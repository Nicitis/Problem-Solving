// 백준 11726 2xn 타일링 2 https://www.acmicpc.net/problem/11727
// 2xn 타일링의 변형 버전. 가장 왼쪽에 올 수 있는 조합이 하나 더 늘었다.
#include <cstdio>

int main()
{
    int n, dp[1001] = {0, 1, 3};
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + (dp[i - 2]<<1)) % 10007;
    printf("%d", dp[n]);
    return 0;
}