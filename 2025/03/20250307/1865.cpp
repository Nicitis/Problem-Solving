#include <iostream>
#include <climits>

#define INF 123456789

using namespace std;

// void print_path(int g[501][501], int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << g[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, n, m, w, s, e, t;
    int g[501][501];

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
            g[s][e] = min(g[s][e], -t);
        }
        // cout << "path\n";
        // print_path(g, n);

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
        for (int i = 1; i <= n; i++)
        {
            if (g[i][i] < 0)
            {
                success = true;
                break;
            }
        }
        cout << (success ? "YES\n" : "NO\n");
    }

    return 0;
}