#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visit[1001];

int minTerms(vector<int>& terms, vector<vector<int>>& adj, int v, int N)
{
    int maxTerm = 0, totalTerm;
    visit[v] = true;
    for (int w : adj[v])
    {
        // 최대 경로 비용 찾기
        if (visit[w])
            totalTerm = terms[w];
        else
            totalTerm = minTerms(terms, adj, w, N);
        
        if (maxTerm < totalTerm)
            maxTerm = totalTerm;
    }
    maxTerm += terms[v];
    terms[v] = maxTerm;
    return maxTerm;
}

int main()
{
    int T, N, K, S;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &K);

        vector<int> buildingTerms(N + 1, 0);
        vector<vector<int>> adj(N + 1, vector<int>());
        
        for (int j = 1; j <= N; j++)
            scanf("%d", &buildingTerms[j]);
        for (int j = 0; j < K; j++)
        {
            // 역그래프 계산
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            adj[v2].push_back(v1);
        }
        scanf("%d", &S);
        
        memset(visit, 0, sizeof(bool) * (N + 1));
        printf("%d\n", minTerms(buildingTerms, adj, S, N));
    }

    return 0;
}