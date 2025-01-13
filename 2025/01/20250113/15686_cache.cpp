#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int GetTotalDistance(vector<int>& selected)
{
    int totalDist = 0;

    for (int i = 0; i < houses.size(); i++)
    {
        int minDist = INT_MAX;
        for (int j = 0; j < selected.size(); j++)
        {
            pair<int, int> chicken = chickens[selected[j]];
            int dist = abs(houses[i].first - chicken.first) + 
                abs(houses[i].second - chicken.second);
            if (dist < minDist)
                minDist = dist;
        }
        totalDist += minDist;
    }
    return totalDist;
}

int MinChickenDistance(vector<int>& selected, int m, int lastSelected)
{
    if (selected.size() == m)
    {
        return GetTotalDistance(selected);
    }

    if (selected.size() < m)
    {
        int minDist = INT_MAX, dist;
        for (int i = lastSelected + 1; i <= chickens.size() - (m - selected.size()); i++)
        {
            selected.push_back(i);
            dist = MinChickenDistance(selected, m, i);
            if (dist < minDist)
                minDist = dist;
            selected.pop_back();
        }
        return minDist;
    }
}

int main()
{
    int n, m, s;

    scanf("%d %d", &n, &m);

    chickens = vector<pair<int, int>>();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s);

            if (s == 1)
                houses.push_back(make_pair(i, j));
            else if (s == 2)
                chickens.push_back(make_pair(i, j));
        }
    }
    vector<int> selected;

    printf("%d\n", MinChickenDistance(selected, m, -1));

    return 0;
}