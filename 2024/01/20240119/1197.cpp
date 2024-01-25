// 2024.01.19. 백준, 1197 최소 스패닝 트리(https://www.acmicpc.net/problem/1197)
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct _edge edge_t;

struct _edge
{
    int v1;
    int v2;
    int weight;
};

// 내림차순으로 정렬
bool compare(edge_t a, edge_t b)
{
    return a.weight < b.weight;
}

// 분리집합의 대표번호를 반환한다. 이때, parent는 자신이 속한 분리집합의 대표 노드를 가리킨다(자신이 대표 노드일 경우 -1).
int find_set(int elem, vector<int>& parent)
{
    if (parent[elem] == -1)
        return elem;

    parent[elem] = find_set(parent[elem], parent);
    return parent[elem];
}

// 두 분리집합을 합친다
void union_set(int a, int b, vector<int>& parent)
{
    int pa = find_set(a, parent);
    int pb = find_set(b, parent);
    parent[pa] = pb;
}

int kruskal(int vertices, vector<edge_t> edges)
{
    int edge_count = 0;
    int total_weight = 0;
    vector<int> disjoint_set(vertices + 1, -1); // 분리 집합의 부모 원소

    // 정렬
    sort(edges.begin(), edges.end(), compare);

    while (edge_count < vertices - 1)
    for (int i = 0; i < edges.size(); i++)
    {
        if (edge_count >= vertices - 1)
            break;

        // 두 정점이 같은 분리집합에 속하면 사이클이 존재하는 것이므로 스킵
        int p1 = find_set(edges[i].v1, disjoint_set);
        int p2 = find_set(edges[i].v2, disjoint_set);
        if (p1 == p2 && p1 != -1 && p2 != -1)
            continue;
        
        // 간선 추가
        total_weight += edges[i].weight;
        edge_count++;
        union_set(edges[i].v1, edges[i].v2, disjoint_set); // 집합을 합침
    }

    return total_weight;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int V, E;
    cin >> V >> E;

    vector<edge_t> edges;

    for (int i = 0; i < E; i++)
    {
        edge_t edge;
        cin >> edge.v1 >> edge.v2 >> edge.weight;
        edges.push_back(edge);
    }

    cout << kruskal(V, edges);

    return 0;
}