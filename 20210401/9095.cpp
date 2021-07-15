// 9095 1, 2, 3 더하기 (https://www.acmicpc.net/problem/9095)
#include <cstdio>

int main()
{
    int dp[12] = { 0, 1, 2, 4 };
    int T, n, i;
    scanf("%d", &T);

    for (i = 4; i <= 11; i++)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    for (i = 0; i < T; i++)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}