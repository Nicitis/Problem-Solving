#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int n;
struct node
{
    vector<vector<int>> dist;
};

vector<node> nodes;
vector<bool> visit;

int dfs(int cur, int dest)
{
    int result = INF;
    int temp;
    visit[cur] = true;

    if (cur == dest)
        return 0;

    vector<vector<int>>& distances = nodes[cur].dist;

    for (int i = 0; i < distances.size(); i++)
    {
        if (visit[distances[i][0]])
            continue;
        
        temp = distances[i][1] + dfs(distances[i][0], dest);
        if (temp < INF)
            result = temp;
    }
    return result;
}

int main(void)
{
    int m, v1, v2, d;

    cin.tie(nullptr); cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    nodes = vector<node>(n + 1);
    visit = vector<bool>(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> v1 >> v2 >> d;

        nodes[v1].dist.push_back({v2, d});
        nodes[v2].dist.push_back({v1, d});
    }

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        for (int j = 1; j <= n; j++)
            visit[j] = false;

        cout << dfs(v1, v2) << '\n';
    }
    
    return 0;
}