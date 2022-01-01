// 백준 1260: DFS와 BFS(C++)
// 인접 행렬 풀이 방법
#include <cstdio>
#include <queue>

bool matrix[1001][1001];
bool visit[1001];

void initialize_visit(int n)
{
    for (int v = 0; v <= n; v++)
        visit[v] = false;
}

// dfs 알고리즘
void print_dfs(int v, int n)
{
    // 새로운 정점에 방문
    visit[v] = true;

    // 출력
    printf("%d ", v);

    // 주변 정점에 재귀 방식으로 방문
    for (int next = 1; next <= n; next++)
    {
        if (matrix[v][next] && !visit[next])
            print_dfs(next, n);
    }
}

// bfs 알고리즘
void print_bfs(int v, int n)
{
    std::queue<int> visit_queue;

    visit_queue.push(v);
    visit[v] = true;

    while (!visit_queue.empty())
    {
        // 새로운 정점에 방문
        v = visit_queue.front();
        visit_queue.pop();

        // 출력
        printf("%d ", v);

        // 주변 정점 추가
        for (int next = 1; next <= n; next++)
        {
            if (matrix[v][next] && !visit[next])
            {
                visit[next] = true;
                visit_queue.push(next);
            }
        }
    }
}

int main()
{
    int n, m, v;
    int s, e;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        matrix[s][e] = true;
        matrix[e][s] = true;
    }

    initialize_visit(n);
    print_dfs(v, n);
    printf("\n");
    initialize_visit(n);
    print_bfs(v, n);
}

/*
// 인접 리스트 풀이방법
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> adj(1001, std::vector<int>(0));
bool visit[1001];

// dfs 알고리즘
void print_dfs(int v, int n)
{
    // 새로운 정점에 방문
    visit[v] = true;

    // 출력
    printf("%d ", v);

    // 주변 정점에 재귀 방식으로 방문
    for (int next = 0; next < adj[v].size(); next++)
    {
        int nextV = adj[v][next];
        if (nextV && !visit[nextV])
            print_dfs(nextV, n);
    }
}

// bfs 알고리즘
void print_bfs(int v, int n)
{
    std::queue<int> visit_queue;

    visit_queue.push(v);
    visit[v] = true;

    while (!visit_queue.empty())
    {
        // 새로운 정점에 방문
        v = visit_queue.front();
        visit_queue.pop();

        // 출력
        printf("%d ", v);

        // 주변 정점 추가
        for (int next = 0; next < adj[v].size(); next++)
        {
            int nextV = adj[v][next];
            if (nextV && !visit[nextV])
            {
                visit[nextV] = true;
                visit_queue.push(nextV);
            }
        }
    }
}

int main()
{
    int n, m, v;
    int s, e;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    // 정렬
    for (int i = 1; i <= n; i++)
        std::sort(adj[i].begin(), adj[i].end());

    memset(visit, (int)false, sizeof(bool) * 1001);
    print_dfs(v, n);
    printf("\n");
    memset(visit, (int)false, sizeof(bool) * 1001);
    print_bfs(v, n);
}
*/