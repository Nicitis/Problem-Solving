#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, K, X, Y, W;
    vector<int> graph[1001];
    int cost[1001], total[1001], in_degree[1001];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;

        fill(in_degree, in_degree + N + 1, 0);

        for (int j = 1; j <= N; j++)
        {
            cin >> cost[j];
            total[j] = cost[j];
            graph[j].clear();
        }
        for (int j = 0; j < K; j++)
        {
            cin >> X >> Y;
            graph[X].push_back(Y);
            in_degree[Y]++;
        }
        cin >> W;

        queue<int> q;
        for (int j = 1; j <= N; j++)
        {
            if (in_degree[j] == 0)
                q.push(j);
        }

        int cur;
        while (!q.empty())
        {
            cur = q.front();
            for (int adj : graph[cur])
            {
                in_degree[adj]--;
                if (in_degree[adj] == 0)
                    q.push(adj);
                total[adj] = max(total[adj], total[cur] + cost[adj]);
            }
            q.pop();
        }
        cout << total[W] << '\n';
    }

    return 0;
}