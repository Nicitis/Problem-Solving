#include <iostream>
#include <cstring>

using namespace std;

int dp[101][10001];
int mem[100], cost[100];

int main()
{
    int n, m, maxCost = 0;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> mem[i];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        maxCost += cost[i];
    }
    
    memset(dp[0], 0, sizeof(int) * maxCost);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= maxCost; j++)
        {
            if (j - cost[i] >= 0 &&
                dp[i][j-cost[i]] + mem[i] > dp[i][j])
                dp[i+1][j] = dp[i][j-cost[i]] + mem[i];
            else
                dp[i+1][j] = dp[i][j];
        }
    }

    for (int j = 0; j <= maxCost; j++)
    {
        if (dp[n][j] >= m)
        {
            cout << j << '\n';
            break;
        }
    }

    return 0;
}