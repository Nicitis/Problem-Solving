#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int c, n;
    const int Inf = 987654321;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;

    vector<pair<int, int>> costCustomerPair;
    int maxCustomer = 0;
    
    for (int i = 0; i < n; i++)
    {
        int cost, customer;
        cin >> cost >> customer;

        costCustomerPair.push_back({cost, customer});
        if (customer > maxCustomer)
            maxCustomer = customer;
    }

    vector<int> minCostVec(c+maxCustomer, Inf);
    minCostVec[0] = 0;

    for (int i = 0; i < c; i++)
    {
        if (minCostVec[i] == Inf)
            continue;
        for (auto p : costCustomerPair)
        {
            minCostVec[i + p.second] = 
                min(minCostVec[i + p.second], minCostVec[i] + p.first);
        }
    }

    // 최소 비용 구하기기
    int minCost = minCostVec[c];
    for (int i = c + 1; i < minCostVec.size(); i++)
    {
        minCost = min(minCost, minCostVec[i]);
    }

    cout << minCost;

    return 0;
}