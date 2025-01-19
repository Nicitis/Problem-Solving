#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph; // 그래프로 해석
vector<int> inDegrees;

void topologicalSort(int N)
{
    vector<bool> visit(N + 1, false);

    queue<int> q;
    vector<int> answer;

    for (int i = 1; i <= N; i++)
    {
        if (inDegrees[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        visit[q.front()] = true;
        answer.push_back(q.front());

        for (int adj : graph[q.front()])
        {
            if (visit[adj])
                continue;
        
            inDegrees[adj]--;
            if (inDegrees[adj] <= 0)
                q.push(adj);
        }
        q.pop();
    }
    
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    graph = vector<vector<int>>(N + 1, vector<int>());
    
    inDegrees = vector<int>(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        graph[A].push_back(B);
        inDegrees[B]++;
    }

    topologicalSort(N);

    return 0;
}