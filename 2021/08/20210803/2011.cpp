#include <cstdio>
#include <cstring>
#define MOD 1000000

int main()
{
    int n, dp[5001] = { 1, 1 }, i, len;
    char str[5001];

    scanf("%s", str);

    len = strlen(str);
    
    if (str[0] == '0')
    {
        printf("0");
        return 0;
    }
    for (i = 2; i <= len; i++)
    {
        if (str[i - 1] == '0')
        {
            if (str[i - 2] != '1' && str[i - 2] != '2')
            {
                printf("0");
                return 0;
            }
            else
                dp[i] = dp[i - 2] % MOD;
        }
        else if (str[i - 2] == '1' || str[i - 2] == '2' && str[i - 1] <= '6')
            dp[i] = (dp[i-2] + dp[i-1]) % MOD;
        else
            dp[i] = dp[i-1] % MOD;
    }
    printf("%d", dp[len]);
}