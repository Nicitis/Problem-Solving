#include <cstdio>

int main(void)
{
    int n, data[1001], dp[1001] = {0}, max_len = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &data[i]);
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (data[j] > data[i] && dp[j] == dp[i])
                dp[i]++;
        }
        if (max_len < dp[i])
            max_len = dp[i];
    }
    printf("%d", max_len);
}