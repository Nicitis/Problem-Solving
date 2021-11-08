#include <cstdio>
#define MOD 1000000000

int main()
{
    int n, k, dp[201], i, j;

    scanf("%d %d", &n, &k);

    for (i = 0; i <= 200; i++)
        dp[i] = 1;
    for (i = 2; i <= k; i++)
    {
        dp[0] = 1;
        for (j = 1; j <= n; j++)
            dp[j] = (dp[j - 1] + dp[j]) % MOD;
    }
    printf("%d", dp[n]);
}