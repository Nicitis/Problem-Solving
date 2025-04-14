#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, completeTime = 0, arrive, check;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<pair<int, int>> cowArriveCheckData; // <arrive, check>
    for (int i = 0; i < n; i++)
    {
        cin >> arrive >> check;
        cowArriveCheckData.push_back(make_pair(arrive, check));
    }

    sort(cowArriveCheckData.begin(), cowArriveCheckData.end());

    for (pair<int, int> p : cowArriveCheckData)
    {
        arrive = p.first;
        check = p.second;
        completeTime = max(arrive, completeTime) + check;
    }
    cout << completeTime;

    return 0;
}