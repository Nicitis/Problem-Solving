#include <iostream>
#include <cstring>

using namespace std;

int dc[5] = { 0, 0, 0, -1, 1 };
int dr[5] = { 0, -1, 1, 0, 0 };

bool map[1000][1000]; // 벽일 경우 true

bool isInMap(int nextr, int nextc, int r, int c)
{
    if (nextr < 0 || nextr >= r || nextc < 0 || nextc >= c)
        return false;
    return true;
}

int main()
{
    int r, c, k, br, bc, sr, sc;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> r >> c;
    cin >> k;

    for (int i = 0; i < r; i++)
    {
        memset(map[i], (int)false, sizeof(map[i]));
    }
    for (int i = 0; i < k; i++)
    {
        // 장애물 입력
        cin >> br >> bc;
        map[br][bc] = true;
    }
    cin >> sr >> sc;
    map[sr][sc] = true;

    int dirarr[4];

    for (int i = 0; i < 4; i++)
    {
        int dir;
        cin >> dir;
        dirarr[i] = dir;
    }

    int prevRow, prevCol;
    while (true)
    {
        prevRow = sr;
        prevCol = sc;

        for (int dir : dirarr)
        {
            // cout << "dir = " << dir << "\n";
            while (isInMap(sr+dr[dir], sc+dc[dir], r, c) && 
                    !map[sr+dr[dir]][sc+dc[dir]])
            {
                sr += dr[dir];
                sc += dc[dir];
                // cout << "cur = " << sr << " " << sc << "\n";
                map[sr][sc] = true;
            }
        }
        if (sr == prevRow && sc == prevCol)
            break;
    }

    cout << sr << " " << sc;

    return 0;
}