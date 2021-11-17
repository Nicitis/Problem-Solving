// 백준 2178: 미로 탐색(C++)
#include <iostream>
#include <queue>
#include <utility>

#define MAX_SIZE 100

using namespace std;

int map[MAX_SIZE + 2][MAX_SIZE + 2];
bool visit[MAX_SIZE + 2][MAX_SIZE + 2];

int xMove[] = { 0, -1, 1, 0 };
int yMove[] = { -1, 0, 0, 1 };

int bfs(int n, int m)
{
    int x, y, i;
    
    queue<pair<char, char>> q;
    q.push(make_pair(1, 1));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visit[y][x] = true;
        
        for (i = 0; i < 4; i++)
        {
            int nextX = x + xMove[i];
            int nextY = y + yMove[i];

            // 1일 경우 이동
            if (map[nextY][nextX] == 1 && !visit[nextY][nextX])
            {
                q.push(make_pair(nextX, nextY));
                map[nextY][nextX] = map[y][x] + 1;
            }
        }

        if (x == m && y == n)
            break;
    }

    return map[n][m];
}

int main()
{
    int n, m, x, y;
    char input[100];
    cin >> n >> m;
    cin.ignore(1, '\n');

    for (y = 1; y <= n; y++)
    {
        cin.getline(input, m + 1);
        for (x = 1; x <= m; x++)
            map[y][x] = input[x - 1] - '0';
    }

    cout << bfs(n, m);
}