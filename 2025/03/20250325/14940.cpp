#include <iostream>
#include <queue>

#define INF -1

using namespace std;

char map[1000][1000];
int dist[1000][1000];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };


int main()
{
    int n, m;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    queue<pair<int, int>> q;
    // <row, col>

    for (int i = 0; i < n; i++)
    {
        fill(&dist[i][0], &dist[i+1][m], INF);
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '2')
            {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == '0' || dist[ny][nx] != INF)
                continue;
            
            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '0')
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    

    return 0;
}