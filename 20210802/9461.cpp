#include <cstdio>

int main()
{
    int t, n, i, j;
    long long dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
    for (j = 11; j < 101; j++)
        dp[j] = dp[j - 1] + dp[j - 5];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
}