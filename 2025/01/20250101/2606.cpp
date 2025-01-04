#include <iostream>
#include <vector>

using namespace std;

struct EdgeGraph
{
    vector<int> adj;
    bool visited;
};

int FindConnection(int v, vector<EdgeGraph>& g)
{
    int connected = 0;
    g[v].visited = true;
    for (int w : g[v].adj)
    {
        if (g[w].visited)
            continue;
        connected += FindConnection(w, g) + 1;
    }
    return connected;
}

int main()
{
    int n, pairs;

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> n >> pairs;

    vector<EdgeGraph> g(n + 1, { vector<int>(), false });
    int v, w;

    for (int i = 0; i < pairs; i++)
    {
        cin >> v >> w;
        g[v].adj.push_back(w);
        g[w].adj.push_back(v);
    }

    // dfs
    printf("%d\n", FindConnection(1, g));

    return 0;
}