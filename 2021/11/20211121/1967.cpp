// 백준 1967: 트리의 지름(C++)
#include <iostream>
#include <vector>
#define MAX(x, y) ((x)>(y)?(x):(y))

using namespace std;

typedef struct _edge
{
    int v;
    int weight;
} Edge;

vector<Edge> adj[10001];
int ans;

int GetMaximumDiameter(int v)
{
    int i, first = 0, second = 0, weight;

    for (const auto& edge : adj[v])
    {
        weight = GetMaximumDiameter(edge.v) + edge.weight;
        if (weight > first)
        {
            second = first;
            first = weight;
        }
        else if (weight > second)
        {
            second = weight;
        }
    }
    ans = MAX(ans, first + second); // 트리의 지름을 구함
    return first; // 자식 노드까지 가장 긴 경로의 길이를 구함
}

int main()
{
    int n, s, e, i, w;
    Edge edge;
    cin >> n;

    for (i = 1; i <= n; i++)
        adj[i].clear();
    for (i = 0; i < n - 1; i++)
    {
        cin >> s >> edge.v >> edge.weight;
        adj[s].push_back(edge);
    }

    GetMaximumDiameter(1); // 1번노드부터 탐색

    cout << ans;
}