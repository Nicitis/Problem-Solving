#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> pos[300000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, treeX, treeY, h;
    long long sumOfShadow = 0LL;

    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;
    
    sort(pos, pos + n);

    treeX = pos[0].first;
    treeY = pos[0].second;

    for (int i = 1; i < n; i++)
    {
        h = treeY - t * (pos[i].first - treeX);
        h = max(0, h);

        sumOfShadow += min(h, pos[i].second);
        if (pos[i].second > h)
        {
            treeX = pos[i].first;
            treeY = pos[i].second;
        }
    }
    cout << sumOfShadow << '\n';

    return 0;
}