#include <cstdio>

int main()
{
    long long dp[91][2] = { 0 };
    int N;
    dp[1][1] = 1;
    dp[2][0] = 1;
    scanf("%d", &N);
    for (int i = 3; i <= N; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    long long pinary = dp[N][0] + dp[N][1];
    printf("%lld\n", pinary);
}