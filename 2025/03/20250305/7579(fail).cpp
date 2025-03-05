#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;
int dp[10000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> visited;

    int memArray[100];
    int costArray[100];
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> memArray[i];
    for (int i = 0; i < n; i++)
        cin >> costArray[i];

    fill(dp, dp + m + 1, INT_MAX);
    dp[0] = 0;
    dp[m] = INT_MAX;
    visited.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int size = visited.size();

        for (int j = size - 1; j >= 0; j--)
        {
            int mem = visited[j];

            // 순회할 때 잘못하면 중복 증가시키는 문제가 생기므로, 위에서부터 아래로 순회해야 한다.
            int nextMem = mem + memArray[i];
            if (nextMem > m)
                nextMem = m;
            if (dp[mem] + costArray[i] < dp[nextMem])
            {
                if (nextMem < m && dp[nextMem] == INT_MAX)
                    visited.push_back(nextMem);
                dp[nextMem] = dp[mem] + costArray[i];
            }
        }
        sort(visited.begin(), visited.end());
    }

    cout << dp[m] << '\n';

    return 0;
}