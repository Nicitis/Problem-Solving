// 백준 1707: 이분 그래프(C++)
// 1. dfs를 통해 색을 칠함
// 2. 이웃한 정점이 색이 같다면 탈락 
// 3. 끝까지 모두 색이 다르다면 이분 그래프
#include <cstdio>
#include <vector>
#include <cstring>

#define V 20000

using namespace std;

vector<vector<int>> adj(V + 1, vector<int>(0));
bool visit[V + 1];
char color[V + 1]; // 색상: 1, 2 (0은 초기화되지 않은 상태)

// dfs 순회를 하며, bipartite graph인지 여부를 반환함
bool dfs(int v, int cur_color)
{
    bool is_bipartite = true;
    int next_color = cur_color == 1 ? 2 : 1;

    color[v] = cur_color;
    visit[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int next = adj[v][i];
        if (!visit[next])
        {
            // 이분 그래프가 아니라는 결과가 하나라도 있으면 이분 그래프가 아니다
            if (!dfs(next, next_color))
                is_bipartite = false;
        }
        // 하나라도 이웃한 정점과 색이 같으면 이분 그래프가 아니다
        else if (color[next] == color[v])
            is_bipartite = false;
    }
    return is_bipartite;
}

void make_graph(int v, int e)
{
    int start, end;
    while (e--)
    {
        scanf("%d %d", &start, &end);
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
}

int main()
{
    int k, v, e;

    scanf("%d", &k);

    while (k--)
    {
        scanf("%d %d", &v, &e);

        // 그래프 구성
        make_graph(v, e);

        bool is_bipartite = true;

        // 모든 정점 순회
        for (int next = 1; next <= v; next++)
        {
            // 연결 요소가 이분 그래프인지 확인한다.
            if (!visit[next] && !dfs(next, 1))
                is_bipartite = false;
        }

        printf("%s\n", is_bipartite ? "YES" : "NO");

        if (k > 0)
        {
            // 초기화하기
            for (int i = 0; i <= V; i++)
                adj[i].clear();
            memset(visit, (int)false, sizeof(bool) * (V + 1));
            memset(color, 0, sizeof(char) * (V + 1));
        }
    }
}