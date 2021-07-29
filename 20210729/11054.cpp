#include <cstdio>

int main()
{
    int n, data[1000], asc_dp[1000], desc_dp[1000], max_len = 0, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    for (i = 0; i < n; i++)
    {
        asc_dp[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (data[j] < data[i] && asc_dp[j] == asc_dp[i])
            {
                asc_dp[i]++;
            }
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        desc_dp[i] = 1;
        for (j = n - 1; j > i; j--)
        {
            if (data[i] > data[j] && desc_dp[i] == desc_dp[j])
            {
                desc_dp[i]++;
            }
        }
        if (max_len < asc_dp[i] + desc_dp[i] - 1)
            max_len = asc_dp[i] + desc_dp[i] - 1;
    }

    printf("%d\n", max_len);
    return 0;
}