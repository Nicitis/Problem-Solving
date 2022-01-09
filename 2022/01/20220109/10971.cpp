// 백준 10971: 외판원 순회 2
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_COST 1000000000

using namespace std;

bool visited[10] = { false };
vector<vector<int>> costMatrix;

int MinTraverseCost(int city, int startCity, int n)
{
    int minCost = MAX_COST;
    int cityCount = 0;
    visited[city] = true;

    for (int next = 0; next < n; next++)
    {
        if (visited[next]) // 방문한 도시를 만나면 도시의 수를 센다.
        {
            cityCount++;
            continue;
        }

        if (costMatrix[city][next] == 0)  // 갈 수 없는 길을 만나면 무시한다.
            continue;
        
        minCost = min(minCost,
            MinTraverseCost(next, startCity, n) + costMatrix[city][next]);
    }

    visited[city] = false;

    if (cityCount == n && costMatrix[city][startCity] != 0)
        minCost = costMatrix[city][startCity];

    return minCost;
}

int main()
{
    int n, minCost = MAX_COST;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    costMatrix = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> costMatrix[i][j];
        }
    }

    // select start city
    for (int i = 0; i < n; i++)
    {
        minCost = min(minCost, MinTraverseCost(i, i, n));
    }

    cout << minCost;

    return 0;
}