#include <iostream>
#include <climits>

#define INF 123456789

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, n, m, w, s, e, t;
    int g[501][501];
    pair<int, int> wormholes[200];

    cin >> tc;

    while (tc--)
    {
        cin >> n >> m >> w;

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = INF;

        // Roads
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            g[s][e] = min(g[s][e], t);
            g[e][s] = min(g[e][s], t);
        }
        // Wormholes
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            wormholes[i] = make_pair(s, e);
            g[s][e] = min(g[s][e], -t);
        }
        // calculate shortest path(Floyd-Warshall)
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        // 음의 가중치 찾기
        bool success = false;
        for (int i = 0; i < w; i++)
        {
            s = wormholes[i].first;
            e = wormholes[i].second;
            if (g[s][e] + g[e][s] < 0)
            {
                success = true;
                break;
            }
        }
        cout << (success ? "YES\n" : "NO\n");
    }

    return 0;
}