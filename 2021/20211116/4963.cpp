// 백준 4963: 섬의 개수
// 모든 섬을 방문하는 문제.
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int map[51][51];

// 1<=x<=w, 1<=y<=h
void dfs(int x, int y, int w, int h)
{
    int dx, dy;
    map[y][x] = 0;

    for (dy = -1; dy <= 1; dy++)
    {
        for (dx = -1; dx <= 1; dx++)
        {
            // 맵 범위에서 벗어나면 생략
            if (x + dx < 1 || x + dx > w ||
                y + dy < 1 || y + dy > h)
                continue;
            
            if (dx == 0 && dy == 0)
                continue;
            
            if (map[y + dy][x + dx] == 1)
                dfs(x + dx, y + dy, w, h);
        }
    }
}

int main()
{
    int w, h, x, y, lands;

    ios_base::sync_with_stdio(false);

    cin >> w >> h;
    while (w != 0 && h != 0)
    {
        lands = 0;
        // 맵 입력
        for (y = 1; y <= h; y++)
            for (x = 1; x <= w; x++)
                cin >> map[y][x];

        // 방문
        for (y = 1; y <= h; y++)
        {
            for (x = 1; x <= w; x++)
            {
                if (map[y][x] == 1)
                {
                    dfs(x, y, w, h);
                    lands++;
                }
            }
        }
        cout << lands << '\n';

        // 초기화
        cin >> w >> h;
    }
}