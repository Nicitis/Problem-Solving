#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int dp[500][500];
    int n;
    int rows[500], cols[500];

    cin >> n;

    for (int i = 0; i < n; i++)
        fill_n(dp[i], n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> rows[i] >> cols[i];
        dp[i][i] = 0;
    }
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            for (int j = i; j < i + k; j++)
            {
                dp[i][i+k] = min(dp[i][i+k], dp[i][j] + dp[j+1][i+k] + rows[i] * cols[j] * cols[i+k]);
            }
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}