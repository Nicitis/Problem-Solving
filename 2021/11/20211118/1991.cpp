// 백준 1991: 트리 순회(C++)
#include <iostream>

using namespace std;

char adj[26][2];

int GetNodeIndex(char c)
{
    return (int)(c - 'A');
}

char GetNode(int i)
{
    return (char)('A' + i);
}

void PreorderTraversal(int nodeIndex)
{
    cout << GetNode(nodeIndex);

    if (adj[nodeIndex][0] != -1)
        PreorderTraversal(adj[nodeIndex][0]);
    if (adj[nodeIndex][1] != -1)
        PreorderTraversal(adj[nodeIndex][1]);
}

void InorderTraversal(int nodeIndex)
{
    if (adj[nodeIndex][0] != -1)
        InorderTraversal(adj[nodeIndex][0]);

    cout << GetNode(nodeIndex);

    if (adj[nodeIndex][1] != -1)
        InorderTraversal(adj[nodeIndex][1]);
}

void PostorderTraversal(int nodeIndex)
{
    if (adj[nodeIndex][0] != -1)
        PostorderTraversal(adj[nodeIndex][0]);
    if (adj[nodeIndex][1] != -1)
        PostorderTraversal(adj[nodeIndex][1]);
        
    cout << GetNode(nodeIndex);
}

int main()
{
    int n, i;
    char node, left, right;
    cin >> n;

    // 입력
    for (i = 0; i < n; i++)
    {
        cin >> node >> left >> right;

        adj[GetNodeIndex(node)][0] = left != '.' ? GetNodeIndex(left) : -1;
        adj[GetNodeIndex(node)][1] = right != '.' ? GetNodeIndex(right) : -1;
    }

    // 그래프 탐색
    PreorderTraversal(0);
    cout << '\n';
    InorderTraversal(0);
    cout << '\n';
    PostorderTraversal(0);
}