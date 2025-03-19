#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, cnt = 0;
    vector<int> adj_list[501];
    bool checked[501];

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        adj_list[i] = vector<int>();
    fill(checked, checked + n, false);
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // bfs
    queue<int> q;

    q.push(1);
    checked[1] = true;

    for (int depth = 0; depth < 2; depth++)
    {
        int popCount = q.size();
        while (popCount--)
        {
            int v = q.front();
            q.pop();
            for (int adj : adj_list[v])
            {
                if (!checked[adj])
                {
                    checked[adj] = true;
                    cnt++;
                    q.push(adj);
                }
            }
        }
    }
    cout << cnt << '\n';
    
    return 0;
}