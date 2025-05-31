#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

inline bool isBroken(vector<pair<int, int>>& edge)
{
    return edge.size() == 0;
}

class FlowEdge
{
public:
    int v;
    int w;
    int flow;
    int maximumFlow;

    FlowEdge(int inV, int inW, int inMaximumFlow) 
        : v(inV), w(inW), flow(0), maximumFlow(inMaximumFlow)
    {}

    void AddFlow(int flow, int startVertex)
    {
        if (forward(startVertex))
            this->flow += flow;
        else
            this->flow -= flow;
    }

    int remainedFlow(int startVertex) const
    {
        if (forward(startVertex))
            return maximumFlow - flow;
        else
            return flow;
    }

    inline bool forward(int vertex) const
    {
        return vertex == v;
    }

    inline int other(int vertex) const
    {
        if (vertex == v)
            return w;
        else
            return v;
    }
};

inline int vertex(int row, int col, int colSize)
{
    return row * colSize + col;
}

bool visited[102];
vector<FlowEdge*> edges[102];
int source;
int sink;

// ford-fulkerson 방식으로 augmented path를 찾는다(sink 발견시 중단)
bool TryFindAugmentedPath(int v, vector<FlowEdge*>& outPath, vector<int>& outVertex)
{
    if (v == sink)
        return true;

    // remained flow > 0인 주변 간선을 탐색한다.
    visited[v] = true;
    outVertex.push_back(v);

    for (FlowEdge* const e : edges[v])
    {
        if (!visited[e->other(v)] && e->remainedFlow(v) > 0)
        {
            outPath.push_back(e);
            if (TryFindAugmentedPath(e->other(v), outPath, outVertex))
                return true;
            outPath.pop_back();
        }
    }
    outVertex.pop_back();
    visited[v] = false;
    return false;
}

int main()
{
    int c;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string map[10];
    const int inf = 987654321;

    cin >> c;

    while (c--)
    {
        int n, m;
        
        cin >> n >> m;

        source = n*m;
        sink = n*m + 1;

        int brokenSeat = 0;
        string line;
        
        for (int i = 0; i <= n * m + 1; i++)
            edges[i].clear();
        
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'x')
                   brokenSeat++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            // V
            for (int j = 0; j < m; j += 2)
            {
                if (map[i][j] == 'x')
                    continue;

                // source 연결
                int cur = vertex(i, j, m);
                FlowEdge* pe = new FlowEdge(source, cur, 1);
                edges[source].push_back(pe);
                
                // 다음 정점과 연결(순방향)
                if (j + 1 == m)
                    break;
                int start = max(i - 1, 0), end = min(i + 1, n - 1);
                for (int row = start; row <= end; row++)
                {
                    int next = vertex(row, j + 1, m);
                    pe = new FlowEdge(cur, next, inf);
                    edges[cur].push_back(pe);
                    edges[next].push_back(pe);
                }
            }
            // U
            for (int j = 1; j < m; j += 2)
            {
                if (map[i][j] == 'x')
                    continue;
                    
                // sink에 연결
                int cur = vertex(i, j, m);
                FlowEdge* pe = new FlowEdge(cur, sink, 1);
                edges[cur].push_back(pe);
                edges[sink].push_back(pe);

                // 다음 정점과 연결(역방향)
                if (j + 1 == m)
                    break;
                int start = max(i - 1, 0), end = min(i + 1, n - 1);
                for (int row = start; row <= end; row++)
                {
                    int next = vertex(row, j + 1, m);
                    pe = new FlowEdge(next, cur, inf);
                    edges[cur].push_back(pe);
                    edges[next].push_back(pe);
                }
            }
        }

        // ford-fulkerson 방법으로 maximum flow 계산
        vector<FlowEdge*> augmentedEdges;
        vector<int> augmentedVertices;
        for (FlowEdge* const edge : edges[source])
        {
            memset(visited, 0, sizeof(visited));
            augmentedEdges.clear();
            augmentedVertices.clear();
            if (edge->flow == 0 && TryFindAugmentedPath(edge->w, augmentedEdges, augmentedVertices))
            {
                edge->AddFlow(1, source);
                for (int i = 0; i < augmentedEdges.size(); i++)
                {
                    augmentedEdges[i]->AddFlow(1, augmentedVertices[i]);
                }
            }
        }

        // maximum matching(maximum flow)을 구한다.
        int maximumMatching = 0;
        for (const FlowEdge* edge : edges[sink])
        {
            maximumMatching += edge->flow;
        }

        // ptr 해제
        // u->v 해제
        for (FlowEdge* sourceEdge : edges[source])
        {
            for (FlowEdge* edge : edges[sourceEdge->w])
            {
                delete edge;
            }
        }
        // source 해제
        for (FlowEdge* edge : edges[source])
        {
            delete edge;
        }
        // sink 해제
        for (FlowEdge* edge : edges[sink])
        {
            delete edge;
        }

        // 앉을 수 있는 자리 = (전체 자리) - (부서진 자리) - (maximum matching)
        int result = n * m - brokenSeat - maximumMatching;
        cout << result << "\n";
    }

    return 0;
}