#include <cstdio>
#define MOD 10007

int main()
{
    int dp[1000][10]={{1,1,1,1,1,1,1,1,1,1}};
    int N, sum = 0;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }
    for (int i = 0; i < 10; i++)
        sum += dp[N - 1][i];
    sum %= MOD;
    printf("%d\n", sum);
}