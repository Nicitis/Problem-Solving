#include <cstdio>
#define MOD 1000000000

int main()
{
    int dp[100][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int N, result = 9;

    scanf("%d", &N);
    
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;
        result = (dp[i][0] + dp[i][9]) % MOD;
        for (int j = 1; j < 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            result = (result + dp[i][j]) % MOD;
        }
    }
    
    printf("%d\n", result);
}