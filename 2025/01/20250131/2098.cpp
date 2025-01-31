#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 987654321
#define START_CITY 0

using namespace std;

int dp[16][(1 << 16)];
int w[16][16];

int N;

int dfs(int before, int visit)
{
    int result = INF;

    if (dp[before][visit] != -1)
        return dp[before][visit];

    if (visit == (1 << N) - 1)
    {
        if (w[before][START_CITY] != 0)
            result = w[before][START_CITY];
        dp[before][START_CITY] = result;
        return result;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (w[before][i] == 0)
            continue;
        if (!(visit & (1 << i)))
        {
            result = min(result, w[before][i] + dfs(i, visit | (1 << i)));
        }
    }
    dp[before][visit] = result;
    return result;
}

int main()
{
    int answer = INF;

    cin >> N;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> w[i][j];

    answer = dfs(START_CITY, (1 << START_CITY));

    cout << answer << '\n';

    return 0;
}