#include <iostream>
#include <vector>
#include <set>

#define INF 123456789

using namespace std;

int dist[401][401];

int main()
{
    int v, e, a, b, c;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
           dist[i][j] = INF;
        dist[i][i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;

        dist[a][b] = c;
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // choose two vertex
    int minDist = INF;
    for (int i = 1; i <= v - 1; i++)
    {
        for (int j = i + 1; j <= v; j++)
        {
            if (dist[i][j] + dist[j][i] < minDist)
                minDist = dist[i][j] + dist[j][i];
        }
    }

    if (minDist != INF)
        cout << minDist;
    else
        cout << "-1";

    return 0;
}