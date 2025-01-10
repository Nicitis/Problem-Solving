#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int cityMap[52][52];
int visitMap[52][52];

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

vector<pair<int, int>> chickens;

int minChickenDistance(vector<int>& selected, int n, int m, int lastSelected)
{
    if (selected.size() < m)
    {
        int minDist = INF, dist;
        for (int i = lastSelected + 1; i <= chickens.size() - (m - selected.size()); i++)
        {
            selected.push_back(i);
            dist = minChickenDistance(selected, n, m, i);
            if (dist < minDist)
                minDist = dist;
            selected.pop_back();
        }
        return minDist;
    }
    
    // msbfs 방식으로 탐색
    int totalDist = 0;
    memset(visitMap, 0, sizeof(int) * 52 * 52);

    // <<row, col>, dist>
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < selected.size(); i++)
    {
        q.push(make_pair(chickens[selected[i]], 0));
    }
    
    while (!q.empty())
    {
        pair<pair<int, int>, int> data = q.front();
        q.pop();

        int row = data.first.first;
        int col = data.first.second;
        int dist = data.second;

        for (int i = 0; i < 4; i++)
        {
            // out of map
            int nextRow = row + dy[i], nextCol = col + dx[i];
            if (nextRow % (n + 1) == 0 || nextCol % (n + 1) == 0)
                continue;
            if (visitMap[nextRow][nextCol])
                continue;
            if (cityMap[nextRow][nextCol] == 1)
            {
                totalDist += dist + 1;
            }
            visitMap[nextRow][nextCol] = 1;
            q.push(make_pair(make_pair(nextRow, nextCol), dist + 1));
        }
    }
    return totalDist;
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    chickens = vector<pair<int, int>>();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cityMap[i][j]);

            if (cityMap[i][j] == 2)
            {
                chickens.push_back(make_pair(i, j));
            }
        }
    }
    vector<int> selected;

    printf("%d\n", minChickenDistance(selected, n, m, -1));

    return 0;
}