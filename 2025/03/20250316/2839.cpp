#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n;
    int dp[5001] = { INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX, 1, };

    cin >> n;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = INT_MAX;
        if (dp[i - 3] != INT_MAX)
            dp[i] = min(dp[i], dp[i - 3] + 1);
        if (dp[i - 5] != INT_MAX)
            dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    cout << (dp[n] != INT_MAX ? dp[n] : -1);

    return 0;
}