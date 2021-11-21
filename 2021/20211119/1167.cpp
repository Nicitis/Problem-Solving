// 백준 1167: 트리의 지름(C++)
// 트리의 지름 <= 10,000 * 100,000 = 10억 <= int의 최댓값
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

#define MAX(x, y) ((x)>(y)?(x):(y))

using namespace std;

vector<pair<int, int>> adj[100001]; // pair<vertex, distance>
int accumulatedDist[100001]; // 방문 안 할 시 -1

void GetHighestTwoDiameter(pair<int,int>* result, int v)
{
    int i, j, dist;
    pair<int, int> next;

    int first = -1, second = -1; // debug

    // v와 연결된 간선 중 가장 (누적 가중치) + (간선 가중치)가 높은 것 두 개를 고른다.
    for (i = 0; i < adj[v].size(); i++)
    {
        next = adj[v][i];
        if (accumulatedDist[next.first] == -1)
            continue;
        dist = accumulatedDist[next.first] + adj[v][i].second;
        // 최댓값보다 큰 경우
        if (dist > result->first)
        {
            result->second = result->first;
            result->first = dist;
        }
        // 그렇지 않고 두 번째 값보다 큰 경우
        else if (dist > result->second)
        {
            result->second = dist;
        }
    }
}

int GetTreeDiameter(int n)
{
    int v, ans = 0, i, remain;
    pair<int, int> next;
    queue<int> q;
    
    // 간선이 하나밖에 없는 노드(간선이 하나인 루트 노드 혹은 터미널 노드)
    // 를 시작점으로 설정한다.
    for (v = 1; v <= n; v++)
    {
        if (adj[v].size() == 1)
            q.push(v);
    }

    // bfs
    while (!q.empty())
    {
        v = q.front();
        q.pop();

        // 이미 방문했다면 skip
        if (accumulatedDist[v] != -1)
        {
            continue;
        }
        else
        {
            // 길이 하나보다 더 남았다면, 방문을 마칠 때까지 기다린다.
            remain = 0;
            for (i = 0; i < adj[v].size(); i++)
            {
                if (accumulatedDist[adj[v][i].first] == -1)
                    remain++;
            }
            if (remain > 1)
                continue;
        }

        // 트리 지름 후보를 찾는다.
        pair<int, int> p = make_pair(0, 0); // 가중치 + 간선 누적 가중치의 최댓값 두 개
        GetHighestTwoDiameter(&p, v);
        ans = MAX(ans, p.first + p.second);
        
        // 트리 누적 간선치 합을 계산한다.
        accumulatedDist[v] = 0;
        for (i = 0; i < adj[v].size(); i++)
        {
            next = adj[v][i];
            if (accumulatedDist[next.first] <= -1)
            {
                if (accumulatedDist[next.first] == -1)
                    // 방문하지 않았다면 큐에 push
                    q.push(next.first);
                continue;
            }
            // 가중치 계산
            accumulatedDist[v] = MAX(accumulatedDist[v],
                accumulatedDist[next.first] + next.second);
        }
    }
    return ans;
}

int main()
{
    int n, s, e, dist, i;
    cin >> n;

    // 그래프 생성(adj[1]부터 시작)
    for (i = 1; i <= n; i++)
        adj[i] = vector<pair<int, int>>(0);
    
    for (i = 1; i <= n; i++)
    {
        cin >> s;
        while (true)
        {
            cin >> e;
            if (e == -1)
                break;
            cin >> dist;
            adj[s].push_back({e, dist});
        }
    }

    memset(accumulatedDist, -1, sizeof(accumulatedDist));

    cout << GetTreeDiameter(n);
}