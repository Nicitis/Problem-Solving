#include <cstdio>
#include <vector>

using namespace std;

vector<int> reversedResult;
vector<vector<int>> graph; // 그래프로 해석
vector<bool> visit;

void dfs(int node)
{
    visit[node] = true;
    
    for (int adj : graph[node])
    {
        if (visit[adj])
            continue;
        dfs(adj);
    }
    reversedResult.push_back(node);
}

void topologicalSort(int N)
{
    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;
        dfs(i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (i < N - 1)
            printf(" ");
        printf("%d", reversedResult[i]);
    }
    printf("\n");
}

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    graph = vector<vector<int>>(N + 1, vector<int>());
    
    visit = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        graph[A].push_back(B);
    }

    topologicalSort(N);

    return 0;
}