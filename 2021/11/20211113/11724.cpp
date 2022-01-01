// 백준 11724: 연결 요소의 개수(C++)
// dfs를 통해서 연결 요소의 개수를 구한다.
// dfs를 실행하면 연결 요소끼리 모두 방문할 수 있으므로, dfs를 실행하는
// 횟수만큼 연결 요소가 존재한다.
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> adj(1001, vector<int>(0));
int visit[1001];

void dfs(int v)
{
    // 방문
    int i, next;
    visit[v] = 1;

    // 인접 정점 확인
    for (i = 0; i < adj[v].size(); i++)
    {
        next = adj[v][i];
        if (!visit[next])
            dfs(next);
    }
}

int main()
{
    int n, m, v, s, e, cc;

    scanf("%d %d", &n, &m);

    // 그래프 구성
    while (m--)
    {
        scanf("%d %d", &s, &e);

        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cc = 0; // 연결 요소

    for (v = 1; v <= n; v++)
    {
        // 모든 정점에 대해 dfs를 실행한다.
        if (!visit[v])
        {
            dfs(v);
            cc++;
        }
    }
    printf("%d", cc);
    return 0;
}