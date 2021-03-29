// 백준 1463 https://www.acmicpc.net/problem/1463
#include <cstdio>
#include <algorithm>
int dp[1000001];

int main()
{
    int n;
    dp[0] = dp[1] = 0;

    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        if (i % 3 == 0)
            dp[i] = std::min(dp[i/3] + 1, dp[i]);
        if (i % 2 == 0)
            dp[i] = std::min(dp[i/2] + 1, dp[i]);
    }

    printf("%d", dp[n]);

    return 0;
}

/*
// 비효율적인 방법
#include <cstdio>
#include <algorithm>
const int LENGTH = 1000001;
int dp[LENGTH]; // 10^6 + 1

int solve(int n)
{
    if (dp[n] != -1)
        return dp[n];
    
    int max = solve(n-1);
    if (n % 3 == 0)
        max = std::min(max, solve(n/3));
    if (n % 2 == 0)
        max = std::min(max, solve(n/2));
    max++;

    dp[n] = max;

    return max;
}

int main()
{
    int n;
    dp[0] = dp[1] = 0;
    for (int i = 2; i < LENGTH; i++)
        dp[i] = -1;
    scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}
*/