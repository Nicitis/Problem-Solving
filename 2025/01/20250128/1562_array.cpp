#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000000

using namespace std;

int dp[101][10][(1 << 10)];

int stairs(int n, int before, int visit)
{
    if (n == 0)
        return visit == (1 << 10) - 1;
    
    if (dp[n][before][visit] != -1)
        return dp[n][before][visit];
    
    int answer = 0;
    if (before > 0) answer = (answer + stairs(n - 1, before - 1, visit | (1 << (before - 1)))) % MOD;
    if (before < 9) answer = (answer + stairs(n - 1, before + 1, visit | (1 << (before + 1)))) % MOD;
    dp[n][before][visit] = answer;

    return answer;
}

int main()
{
    int N;

    cin >> N;

    memset(dp, -1, sizeof(dp));

    int answer = 0;
    for (int i = 1; i < 10; i++)
    {
        answer = (answer + stairs(N-1, i, (1 << i))) % MOD;
    }
    cout << answer << '\n';

    return 0;
}