#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct MemCost
{
    int memory;
    int cost;
};

MemCost memCostArr[100];
// int minCost = INT_MAX;
int maximumDepth;

int FindMinimumCost(int start, int end, int currentCost, int remainedBytes, int depth)
{
    if (remainedBytes <= 0)
    {
        maximumDepth = depth - 1;
        return currentCost;
    }
    else if (depth >= maximumDepth)
    {
        return INT_MAX;
    }

    int minCost = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        int cost = FindMinimumCost(i + 1, end, 
            currentCost + memCostArr[i].cost, 
            remainedBytes - memCostArr[i].memory, depth + 1);
        if (cost != INT_MAX)
        {
            if (cost < minCost)
                minCost = cost;
            if (depth >= maximumDepth)
                break;
        }
    }
    return minCost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    maximumDepth = n;

    for (int i = 0; i < n; i++)
        cin >> memCostArr[i].memory;
    for (int i = 0; i < n; i++)
        cin >> memCostArr[i].cost;

    sort(memCostArr, memCostArr + n, [](MemCost a, MemCost b){
        return a.cost < b.cost;
    });

    cout << FindMinimumCost(0, n - 1, 0, m, 0) << '\n';

    return 0;
}