#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int cost[20][20];
int dp[(1 << 20) - 1];

int N;

int dfs(int person, int mask)
{
    if (person == N)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    // person에게 job번 일을 맡긴다
    int result = INT_MAX;
    for (int job = 0; job < N; job++)
    {
        if (!(mask & (1 << job)))
        {
            result = min(result, dfs(person + 1, mask | (1 << job)) + cost[person][job]);
        }
    }
    dp[mask] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << '\n';

    return 0;
}