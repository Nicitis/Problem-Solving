#include <iostream>
#include <climits>

using namespace std;

#define INF 987654321

int cost[20][20];
int dp[(1 << 20) - 1];

int count_bits(int bits)
{
    int count = 0;
    while (bits)
    {
        count += bits & 0x01;
        bits = bits >> 1;
    }
    return count;
}

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

    dp[0] = 0;
    for (int i = 1; i < (1 << N); i++)
        dp[i] = INF;

    for (int i = 0; i < (1 << N); i++)
    {
        int x = count_bits(i);

        for (int j = 0; j < N; j++)
        {
            if ((i & (1 << j)) != 0)
                continue;
            
            int next = (i | (1 << j));
            if (dp[i] + cost[x][j] < dp[next])
            {
                dp[next] = dp[i] + cost[x][j];
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}