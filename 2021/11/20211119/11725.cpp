// 백준 11725: 트리의 부모 찾기(C++)
// 1번 노드와 이어진 트리부터 주어지지 않을 수도 있으므로, 우선 그래프부터 완성한 후 부모를 설정한다.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int parent[100001];

void dfs(int v)
{
    int i, next;
    for (i = 0; i < adj[v].size(); i++)
    {
        next = adj[v][i];
        // 부모가 설정되지 않은 노드를 순회하며 parent를 설정
        if (parent[next] == 0)
        {
            parent[next] = v;
            dfs(next);
        }
    }
}

int main()
{
    int n, i, v1, v2;
    cin >> n;

    adj = vector<vector<int>>(n + 1, vector<int>(0));

    for (i = 0; i < n - 1; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    // 1번 노드부터 순회한다.
    parent[1] = -1;
    dfs(1);

    for (i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }
    return 0;
}