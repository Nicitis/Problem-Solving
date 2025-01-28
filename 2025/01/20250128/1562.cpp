#include <iostream>
#include <vector>
#include <cstring>

#define MAX_VISIT 0x3FF
#define MOD 1000000000

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<vector<int>> dp(10, vector<int>(MAX_VISIT + 1, 0ll));
    vector<vector<int>> prev;

    for (int i = 1; i < 10; i++)
    {
        dp[i][(1 << i)] = 1;
    }

    for (int n = 2; n <= N; n++)
    {
        prev = dp;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j <= MAX_VISIT; j++)
                dp[i][j] = 0ll;

        for (int i = 0; i < 10; i++)
        {
            for (int visit = 0; visit <= MAX_VISIT; visit++)
            {
                if (i > 0)
                {
                    int next = visit | (1 << (i - 1));
                    dp[i - 1][next] = (dp[i - 1][next] + prev[i][visit]) % MOD;
                    
                }
                if (i < 9)
                {
                    int next = visit | (1 << (i + 1));
                    dp[i + 1][next] = (dp[i + 1][next] + prev[i][visit]) % MOD;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer = (answer + dp[i][MAX_VISIT]) % MOD;
    }
    cout << answer << '\n';

    return 0;
}