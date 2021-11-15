// 백준 10451: 순열 사이클(C++)
#include <cstdio>
#include <cstring>

int adj[1001];
bool visit[1001];
int cycles = 0;

// dfs 탐색을 하고, 더 이상 순회할 수 없을 때 만난 정점을 반환한다.
int dfs(int v)
{
    int last = 0;
    int next = adj[v];
    visit[v] = true;
    if (!visit[next])
        last = dfs(next);
    else // 이미 방문한 정점이면 정점 번호를 반환
        last = next;

    // 마지막 정점이 자신에게 접근 가능할 경우, cycle의 수를 증가
    if (last == v)
    {
        last = 0;
        cycles++;
    }
    return last;
}

void make_graph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &adj[i]);
    }
}

int main()
{
    int k, n, v;
    scanf("%d", &k);
    while (k--)
    {
        cycles = 0;
        // 그래프 생성
        scanf("%d", &n);
        make_graph(n);

        // 순열 사이클의 수를 센다
        for (v = 1; v <= n; v++)
        {
            if (!visit[v])
                dfs(v);
        }

        printf("%d\n", cycles);

        memset(adj, 0, sizeof(adj));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}