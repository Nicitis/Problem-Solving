#include <cstdio>

int main()
{
    int n, data[1000], dp[1000], max_len = 0, i, j, asc, desc;
    // bool ascending[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        // dp[i] = 1; ascending[i] = true;
        // ascending[i] = true;
        // 뭐지? dp를 두 개를 둬야 하나? 증가 상태일 때 최대 값, 감소 상태일 때 최대 값?
        asc = 1, desc = 1;
        for (j = 0; j < i; j++)
        {
            if (data[j] < data[i] && dp[j] == asc)
            {
                asc++;
            }
            if (data[j] > data[i] && dp[j] >= desc)
            {
                desc++;
            }
        }
        if (asc >= desc)
        {
            dp[i] = asc;
        }
        else
        {
            dp[i] = desc;
        }
        printf("[i=%d]data = %d,dp=%d\n", i, data[i], dp[i]);

        if (max_len < dp[i])
            max_len = dp[i];
    }
    printf("%d\n", max_len);
    return 0;
}