#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int cost[20][20];
int dp[(1 << 20) - 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    queue<int> indexQueue;
    indexQueue.push(0);

    for (int job = 0; job < N; job++)
    {
        int indices = indexQueue.size();

        for (int repeat = 0; repeat < indices; repeat++)
        {
            int idx = indexQueue.front();
            indexQueue.pop();

            for (int i = 0; i < N; i++)
            {
                if ((idx & (1 << i)) != 0)
                    continue;

                if (dp[idx | (1 << i)] == -1)
                {
                    dp[idx | (1 << i)] = dp[idx] + cost[i][job];
                    indexQueue.push(idx | (1 << i));
                }
                else if (dp[idx] + cost[i][job] < dp[idx | (1 << i)])
                {
                    dp[idx | (1 << i)] = dp[idx] + cost[i][job];
                }
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}