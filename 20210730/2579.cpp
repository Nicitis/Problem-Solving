// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int n, score[301], dp[301], i, max_score = 0;
    
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n;

//     for (i = 1; i <= n; i++)
//     {
//         cin >> score[i];
//         dp[i] = max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];
//     }
//     cout << dp[n];
// }

#include <cstdio>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, score[301] = {0}, dp[301], i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &score[i]);
    for (i = 1; i <= n; i++)
    {
        dp[i] = max((i > 3 ? dp[i - 3] : 0) + score[i - 1], i > 2 ? dp[i - 2] : 0) + score[i];
    }
    printf("%d", dp[n]);
}