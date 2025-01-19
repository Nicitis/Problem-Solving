#include <cstdio>
#include <vector>

#define MAX_CNT 32001

using namespace std;

int ans[MAX_CNT];
vector<int> graph[MAX_CNT]; // 그래프로 해석
bool visit[MAX_CNT];
int cnt;

void dfs(int node)
{
    visit[node] = true;
    for (int adj : graph[node])
    {
        if (!visit[adj])
            dfs(adj);
    }
    ans[cnt++] = node;
}

void topologicalSort(int N)
{
    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;
        dfs(i);
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", ans[N - i]);
    }
    printf("\n");
}

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        graph[A].push_back(B);
    }

    topologicalSort(N);

    return 0;
}