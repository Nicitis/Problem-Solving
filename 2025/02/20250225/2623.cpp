#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{
    vector<int> adj;
    int inDegree;

    Graph() : adj(vector<int>()), inDegree(0)
    {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v, w;
    Graph g[1001];
    bool visit[1001];
    int answer[1000], cnt = 0;
    
    cin >> n >> m;

    fill(g, g + n + 1, Graph());
    fill(visit, visit + n + 1, false);
    
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k; 
        v = -1;
        for (int i = 0; i < k; i++)
        {
            cin >> w;
            if (v != -1)
            {
                g[v].adj.push_back(w);
                g[w].inDegree++;
            }
            v = w;
        }
    }

    // start queue
    queue<int> vq;

    for (int i = 1; i <= n; i++)
    {
        if (g[i].inDegree == 0)
        {
            vq.push(i);
            visit[i] = true;
        }
    }

    while (!vq.empty())
    {
        v = vq.front();
        vq.pop();
        answer[cnt++] = v;

        for (int w : g[v].adj)
        {
            g[w].inDegree--;
            if (g[w].inDegree == 0 && !visit[w])
            {
                vq.push(w);
                visit[w] = true;
            }
        }
    }
    
    // check
    if (cnt < n)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}