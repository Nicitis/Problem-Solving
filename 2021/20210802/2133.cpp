#include <cstdio>

int main()
{
    int n, dp = 0, current = 1, i, prevDp;
    scanf("%d", &n);
    if (n % 2 == 1)
    {
        printf("0");
        return 0;
    }
    for (i = 2; i <= n; i += 2)
    {
        prevDp = dp;
        dp += current * 2;
        current = current * 3 + prevDp;
    }
    printf("%d", current);
    return 0;
}

// int main()
// {
//     int n, dp[31] = {1, 0, 3}, sum = 0, i, j;

//     scanf("%d", &n);

//     if (n % 2 == 1)
//     {
//         printf("0");
//         return 0;
//     }

//     for (i = 4; i <= n; i += 2)
//     {
//         dp[i] = dp[i-2] * 3;
//         for (j = 0; j < i - 2; j += 2)
//         {
//             dp[i] += dp[j] << 1;
//         }
//     }
    
//     printf("%d", dp[n]);
// }