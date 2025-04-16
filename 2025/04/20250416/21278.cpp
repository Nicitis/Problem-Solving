#include <iostream>
#include <vector>
#include <algorithm>

#define INF 123456789

using namespace std;

int dist[101][101];

void shortest_path_all_pair(int n)
{
    // 플로이드 워셜 알고리즘 기반 최단 경로 계산
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                // i->j
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    int n, m, a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    // 1. 모든 건물에서 모든 건물로 최단 경로를 구한다.
    shortest_path_all_pair(n);

    // 2. 모든 건물로 접근성 합을 최소화하는 조합을 구한다.
    int first = -1, second = -1, minimum_total = INF, dist_total;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // 접근성 합을 구한다.
            dist_total = 0;
            for (int k = 1; k <= n; k++)
            {
                dist_total += min(dist[i][k], dist[j][k]);
            }

            if (dist_total < minimum_total)
            {
                first = i;
                second = j;
                minimum_total = dist_total;
            }
        }
    }
    cout << first << " " << second << " " << minimum_total * 2;

    return 0;
}