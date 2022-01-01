// 백준 2448: 별 찍기 - 11
#include <iostream>
#include <vector>
#include <string>

#define MAX_LEVEL 11

using namespace std;

int widthsOnLevel[MAX_LEVEL + 1] = { 0, 5 };
vector<string> map;

int GetLevel(int n)
{
    int level = 1;
    while (n > 3)
    {
        n = n >> 1;
        level++;
    }
    return level;
}

void CalculateMap(int x, int y, int n, int level)
{
    if (level == 1)
    {
        map[y].replace(x, 5, "  *  ");
        map[y+1].replace(x, 5, " * * ");
        map[y+2].replace(x, 5, "*****");

        return;
    }
    
    CalculateMap(x + n/2, y, n/2, level-1);
    CalculateMap(x, y+n/2, n/2, level-1);
    CalculateMap(x + widthsOnLevel[level-1] + 1, y+n/2, n/2, level-1);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    
    int level = GetLevel(n);

    for (int i = 2; i < MAX_LEVEL + 1; i++)
    {
        widthsOnLevel[i] = widthsOnLevel[i - 1] * 2 + 1;
    }

    map = vector<string>(n, string(widthsOnLevel[level], ' '));

    CalculateMap(0, 0, n, level);

    for (int y = 0; y < n; y++)
    {
        cout << map[y] << '\n';
    }

    return 0;
}