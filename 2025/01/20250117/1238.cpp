#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M, X;
    vector<pair<int, int>> graph[1001]; // <vertex, time>
    vector<pair<int, int>> reversedGraph[1001]; // <vertex, time>
    int distance[1001];
    int reversedDistance[1001];

    scanf("%d %d %d", &N, &M, &X);

    for (int i = 0; i < M; i++)
    {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);

        graph[v1].push_back(make_pair(v2, w));
        reversedGraph[v2].push_back(make_pair(v1, w));
    }

    for (int i = 0; i <= N; i++)
    {
        distance[i] = INT_MAX;
        reversedDistance[i] = INT_MAX;
    }

    distance[X] = 0;
    reversedDistance[X] = 0;

    // X -> other(graph)
    priority_queue<pair<int, int>> pq; // <-weight, vertex>
    pq.push(make_pair(0, X));
    
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        for (auto& adj : graph[v])
        {
            if (distance[v] + adj.second < distance[adj.first])
            {
                distance[adj.first] = distance[v] + adj.second;
                pq.push(make_pair(-distance[adj.first], adj.first));
            }
        }
    }

    // other -> X(reversed)
    pq.push(make_pair(0, X));
    int students = N;
    
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        for (auto& adj : reversedGraph[v])
        {
            if (reversedDistance[v] + adj.second < reversedDistance[adj.first])
            {
                reversedDistance[adj.first] = reversedDistance[v] + adj.second;
                pq.push(make_pair(-reversedDistance[adj.first], adj.first));
            }
        }
    }

    int maximumDistance = 0;
    for (int i = 1; i <= N; i++)
    {
        if (distance[i] + reversedDistance[i] > maximumDistance)
            maximumDistance = distance[i] + reversedDistance[i];
    }

    printf("%d\n", maximumDistance);

    return 0;
}