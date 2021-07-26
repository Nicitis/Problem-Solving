#include <cstdio>

int max(int a, int b)
{
    return a > b ? a : b;
}

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    int N, dp[10001], amount;
    scanf("%d", &N);

    int prev;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &amount);

        if (i >= 4)
            dp[i] = max3(dp[i-1], dp[i-2] + amount, dp[i-3] + prev + amount);
        else if (i == 1)
            dp[i] = amount;
        else if (i == 2)
            dp[i] = dp[i - 1] + amount;
        else
            dp[i] = max3(dp[1] + prev, prev + amount, dp[1] + amount);
        
        prev = amount;
    }
    printf("%d\n", dp[N]);
}