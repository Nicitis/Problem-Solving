#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareGems(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> gems;
    vector<int> bags;

    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        gems.push_back(make_pair(m, v));
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(gems.begin(), gems.end(), compareGems);
    sort(bags.begin(), bags.end());

    long long totalValue = 0LL;
    int gemIdx = 0;
    priority_queue<int> gemValuePQ; // maxPQ

    for (int i = 0; i < k; i++)
    {
        // push all gems to PQ that are lighter than the bag's limit.
        while (gemIdx < n && gems[gemIdx].first <= bags[i])
        {
            gemValuePQ.push(gems[gemIdx].second);
            gemIdx++;
        }
        
        if (gemValuePQ.empty())
            continue;

        totalValue += gemValuePQ.top();
        gemValuePQ.pop();
    }

    cout << totalValue << '\n';

    return 0;
}