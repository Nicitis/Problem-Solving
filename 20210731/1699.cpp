#include <cstdio>

int main(void)
{
    int n, dp[100001] = {0}, min, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (j = 2; j * j <= i; j++)
        {
            if (dp[i] > dp[i - j * j] + 1)
                dp[i] = dp[i - j * j] + 1;
        }
    }
    printf("%d", dp[n]);
}