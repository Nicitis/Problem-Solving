#include <iostream>
#include <cstring>

using namespace std;

bool dp[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, s, e;
    int data[2001];
    memset(dp, 0, sizeof(dp));

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }

    // calculate dp(the case: (e - s + 1) is odd)
    for (int center = 1; center <= n; center++)
    {
        dp[center][center] = true;
        for (int i = 1; center - i >= 1 && center + i <= n; i++)
        {
            if (data[center - i] != data[center + i])
                break;
            dp[center - i][center + i] = true;
        }
    }

    // calculate dp(the case: (e - s + 1) is even)
    for (int center = 1; center <= n; center++)
    {
        for (int i = 0; center - i >= 1 && center + i + 1 <= n; i++)
        {
            if (data[center - i] != data[center + 1 + i])
                break;
            dp[center - i][center + 1 + i] = true;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << (dp[s][e] ? "1\n" : "0\n");
    }

    return 0;
}