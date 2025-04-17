#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    int n, m, a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> adj[1001];
    int in_deg[1001];
    int semester[1001];

    cin >> n >> m;

    memset(in_deg, 0, sizeof(in_deg));

    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        in_deg[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (in_deg[i] == 0)
        {
            q.push(i);
            semester[i] = 1;
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int w : adj[v])
        {
            if (--in_deg[w] == 0)
            {
                q.push(w);
                semester[w] = semester[v] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << semester[i] << " ";
    }
    
    return 0;
}