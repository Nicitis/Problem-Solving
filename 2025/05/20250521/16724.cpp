#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
string board[1000];
int visit[1000][1000] = { 0, };
int currentId = 1;

bool FindCycle(int x, int y)
{
    // 내 사이클에서 방문한 곳이면 OK
    if (visit[y][x] == currentId)
        return true;
    else if (visit[y][x])
        return false;

    int dir;
    switch (board[y][x])
    {
        case 'U': dir = 0; break;
        case 'L': dir = 1; break;
        case 'R': dir = 2; break;
        case 'D': dir = 3; break;
    }
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
    {
        nx = x;
        ny = y;
    }

    visit[y][x] = currentId;
    return FindCycle(nx, ny);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int cycles = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (visit[y][x])
                continue;
            if (FindCycle(x, y))
                cycles++;
            currentId++;
        }
    }

    cout << cycles;

    return 0;
}