#include <iostream>
#include <queue>
#include <vector>

#define INF 123456789

using namespace std;

int main()
{
    priority_queue<pair<int, int>> pq; // <-dist, vertex>

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<pair<int, int>>> graph(V + 1, vector<pair<int, int>>()); // <dist, vertex>

    for (int i = 0; i < E; i++)
    {
        int v, w, dist;
        cin >> v >> w >> dist;
        graph[v].push_back(make_pair(dist, w));
    }
    
    vector<int> shortest(V + 1, INF);
    pq.push(make_pair(0, S));
    shortest[S] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top(); // 가장 값 큰 것 선택
        int dist = -p.first;
        pq.pop();
        
        // 이웃한 정점 찾기
        for (auto adj : graph[p.second])
        {
            if (dist + adj.first < shortest[adj.second])
            {
                shortest[adj.second] = shortest[p.second] + adj.first;
                pq.push(make_pair(-shortest[adj.second], adj.second));
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (shortest[i] == INF)
            cout << "INF\n";
        else
            cout << shortest[i] << '\n';
    }
    return 0;
}