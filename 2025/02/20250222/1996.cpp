#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;

    cin >> n;

    vector<string> mineMap(n);
    vector<string> map(n, string(n, '0'));

    for (int i = 0; i < n; i++)
    {
        cin >> mineMap[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mineMap[i][j] == '.')
                continue;
            map[i][j] = '*';
            int mines = mineMap[i][j] - '0';
            for (int y = i - 1; y <= i + 1; y++)
            {
                for (int x = j - 1; x <= j + 1; x++)
                {
                    if (y < 0 || y >= n || x < 0 || x >= n)
                        continue;
                    if (x == j && y == i)
                        continue;
                    if (mineMap[y][x] != '.')
                        continue;
                    if (map[y][x] == 'M')
                        continue;
                    map[y][x] += mines;
                    if (map[y][x] > '9')
                        map[y][x] = 'M';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << map[i] << '\n';

    return 0;
}