#include <cstdio>
#include <cstring>

int map[10][10]; // border = wall
bool visit[10][10];

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int FindInfectedArea(int x, int y, int n, int m)
{
    int area = 1;
    visit[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        if (!visit[y + dy[i]][x + dx[i]] &&
            map[y + dy[i]][x + dx[i]] != 1)
            area += FindInfectedArea(x + dx[i], y + dy[i], n, m);
    }
    return area;
}

int SafeArea(int numberOfWalls, int n, int m)
{
    // find safe area
    memset(visit, 0, 100 * sizeof(bool));
    int infected = 0;
    int maximumInfected = n * m - numberOfWalls;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (map[y][x] == 2 && !visit[y][x])
            {
                infected += FindInfectedArea(x, y, n, m);
                if (infected >= maximumInfected)
                    return 0;
            }
        }
    }
    return n * m - numberOfWalls - infected;
}

int LargestSafeArea(int initialWalls, int n, int m, int row, int col, int remainedWalls)
{
    int largest = 0;
    map[row][col] = 1;
    remainedWalls--;

    if (remainedWalls == 0)
    {
        largest = SafeArea(initialWalls + 3, n, m);
        map[row][col] = 0;
        return largest;
    }
    
    int startCol, endCol, area;
    for (int i = row; i <= n; i++)
    {
        startCol = i == row ? col + 1 : 1;
        endCol = i == n ? (m - remainedWalls + 1) : m;

        for (int j = startCol; j <= endCol; j++)
        {
            if (map[i][j] != 0)
                continue;
            area = LargestSafeArea(initialWalls, n, m, i, j, remainedWalls);
            if (area > largest)
                largest = area;
        }
    }

    map[row][col] = 0;

    return largest;
}

int main()
{
    int n, m, initialWalls = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i % (n + 1) == 0 || j % (m + 1) == 0)
                map[i][j] = 1;
            else
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 1)
                    initialWalls++;
            }
        }
    }

    int largest = 0, area;
    for (int i = 1; i <= n; i++)
    {
        int endCol = i == n ? (m - 2) : m;
        for (int j = 1; j <= endCol; j++)
        {
            if (map[i][j] != 0)
                continue;
            area = LargestSafeArea(initialWalls, n, m, i, j, 3);
            if (area > largest)
                largest = area;
        }
    }
    printf("%d\n", largest);
}