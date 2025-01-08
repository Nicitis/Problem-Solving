#include <iostream>
#include <vector>
#include <set>

#define NONE -1
#define INF 123456789

using namespace std;

struct DijkstraGraph
{
    // int prevVertex;
    int accWeight;
    vector<pair<int, int>> adj; // <next vertex, dist>

    DijkstraGraph()
    {
        // prevVertex = NONE;
        accWeight = INF;
        adj = vector<pair<int, int>>();
    }
};



class IndexedPriorityQueue
{
private:
    vector<int> indexTable; // vertex -> heap index
    vector<pair<int, int>> heap; // pair of vertex and accumulated distance

public:
    IndexedPriorityQueue(int V)
    {
        indexTable = vector<int>(V + 1, NONE);
        heap = vector<pair<int, int>>(1, make_pair(0, 0)); // padding 0
    }

    bool Empty()
    {
        return heap.size() <= 1;
    }

    bool Contain(int vertex)
    {
        return indexTable[vertex] != NONE;
    }

    void Push(int vertex, int newDistance)
    {
        heap.push_back(make_pair(vertex, newDistance));
        indexTable[vertex] = heap.size() - 1;

        HeapifyUp(heap.size() - 1, newDistance);
    }

    int Pop()
    {
        int top = heap[1].first;
        Swap(1, heap.size() - 1); // 마지막 요소를 처음으로 옮기기
        heap.pop_back();
        indexTable[top] = NONE;

        int index = 1;
        int child = index << 1; // *2
        while (child < heap.size())
        {
            if (child + 1 < heap.size() && 
                heap[child].second > heap[child + 1].second)
                child++;
            if (heap[index].second < heap[child].second)
                break;
            Swap(index, child);
            index = child;
            child = child << 1; // *2
        }

        return top;
    }

    void ChangeDown(int vertex, int newDistance)
    {
        int index = indexTable[vertex];
        heap[index].second = newDistance;

        HeapifyUp(index, newDistance);
    }

    void PrintTableAndHeap()
    {
        // Table
        cout << "==============\n";
        cout << "Table:\n";
        for (int i = 1; i < indexTable.size(); i++)
        {
            cout << i << ": " << indexTable[i] << '\n';
        }

        // Heap
        cout << "Heap:\n";
        for (int i = 1; i < heap.size(); i++)
        {
            cout << heap[i].first << "(" << heap[i].second << ")" << " ";
        }
        cout << "\n==============\n";
    }

private:
    void HeapifyUp(int initialIndex, int newDistance)
    {
        int index = initialIndex;
        int parent = initialIndex / 2;

        // heapify up
        while (parent > 0)
        {
            if (newDistance >= heap[index / 2].second)
                break;
            
            Swap(index, index / 2);
            index = parent;
            parent /= 2;
        }
    }

    void Swap(int idx1, int idx2)
    {
        pair<int, int> temp = heap[idx1];
        heap[idx1] = heap[idx2];
        heap[idx2] = temp;

        indexTable[heap[idx1].first] = idx1;
        indexTable[heap[idx2].first] = idx2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, S;

    cin >> V >> E;
    cin >> S;

    vector<DijkstraGraph> graph(V + 1, DijkstraGraph()); // first one is dummy

    graph[S].accWeight = 0;

    for (int i = 0; i < E; i++)
    {
        int v, w, dist;
        cin >> v >> w >> dist;
        graph[v].adj.push_back(make_pair(w, dist));
    }

    // calculate distance
    IndexedPriorityQueue minPQ(V);
    minPQ.Push(S, 0);

    while (!minPQ.Empty())
    {
        // find closest one
        int cur = minPQ.Pop();

        // relax edge
        for (auto edge : graph[cur].adj)
        {
            int next = edge.first;
            int dist = edge.second;

            if (graph[cur].accWeight + dist < graph[next].accWeight)
            {
                int newDist = graph[cur].accWeight + dist;
                graph[next].accWeight = newDist;
                if (!minPQ.Contain(next))
                    minPQ.Push(next, newDist);
                else
                    minPQ.ChangeDown(next, newDist);
            }
        }
    }

    // Show all distances
    for (int i = 1; i <= V; i++)
    {
        if (graph[i].accWeight == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << graph[i].accWeight << '\n';
        }
    }

    return 0;
}