#include <iostream>

using namespace std;

bool map[101][101];

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

int SizeOfTrash(int r, int c)
{
    int size = 1;
    map[r][c] = false;

    for (int dir = 0; dir < 4; dir++)
    {
        int nextR = r + dy[dir];
        int nextC = c + dx[dir];

        if (map[nextR][nextC])
            size += SizeOfTrash(nextR, nextC);
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k, r, c;

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;

        map[r][c] = true;
    }

    int biggestSize = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j])
                biggestSize = max(biggestSize, SizeOfTrash(i, j));
        }
    }
    cout << biggestSize << '\n';

    return 0;
}