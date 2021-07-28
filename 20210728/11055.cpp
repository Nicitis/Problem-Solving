#include <cstdio>

int main()
{
    int n, array[1001], dp[1001] = {0}, max_sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
        for (int j = 1; j < i; j++)
        {
            if (array[j] < array[i] && dp[j] > dp[i])
                dp[i] = dp[j];
        }
        dp[i] += array[i];
        if (dp[i] > max_sum) max_sum = dp[i];
    }
    printf("%d", max_sum);
}