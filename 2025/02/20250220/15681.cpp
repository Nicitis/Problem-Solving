#include <iostream>
#include <vector>

using namespace std;

// U번 노드 쿼리의 정답: (U번 트리의 모든 자식 수) + 1

struct TreeNode
{
    int parent;
    vector<int> adj;
    int count;
    
    TreeNode() 
    : parent(-1)
    , adj(vector<int>())
    , count(1)
    {
    }
};

vector<TreeNode> nodeList;

int Traverse(int v)
{
    if (v == -1)
        return 0;

    TreeNode& node = nodeList[v];
    int count = 1;
    for (int u : node.adj)
    {
        if (u == node.parent)
            continue;
        nodeList[u].parent = v;
        count += Traverse(u);
    }
    node.count = count;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q, u, v;

    cin >> n >> r >> q;

    nodeList = vector<TreeNode>(n+1, TreeNode());

    for (int i = 0; i < n-1; i++)
    {
        cin >> u >> v;

        nodeList[u].adj.push_back(v);
        nodeList[v].adj.push_back(u);
    }

    // calculate count and parent.
    Traverse(r);

    for (int i = 0; i < q; i++)
    {
        cin >> u;
        cout << nodeList[u].count << '\n';
    }

    return 0;
}