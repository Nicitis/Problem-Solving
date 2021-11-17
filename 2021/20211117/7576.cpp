// 백준 7576: 토마토(C++)
// 그래프 문제
// 각 토마토 위치마다 익는 데에 걸리는 시간을 기록한다.
// dfs로 토마토가 익는 최소 기간을 기록
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define MAX_LEN 1000

#define MAX(X, Y) ((X)>(Y)?(X):(Y))

using namespace std;

int map[MAX_LEN + 2][MAX_LEN + 2]; // map[y][x]
// 0은 익지 않은 토마토, 1은 익은 토마토, -1은 토마토가 없는 칸
// 토마토가 익는 데에 걸리는 시간을 저장함.

int xMove[4] = { 0, -1, 1, 0 };
int yMove[4] = { -1, 0, 0, 1 };

// 토마토가 존재하는 모든 정점에서 동시에 bfs를 진행한다.
void SimultaneousBfs(int m, int n)
{
    int x, y, i, nextX, nextY;
    queue<pair<int, int>> q;
    pair<int, int> position;

    // 토마토가 존재하는 모든 정점을 queue에 넣는다.
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= m; x++)
        {
            // 토마토가 존재할 경우(==1) 방문한다.
            if (map[y][x] == 1)
                q.push(make_pair(x, y));
        }
    }

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
    
        for (i = 0; i < 4; i++)
        {
            nextX = x + xMove[i];
            nextY = y + yMove[i];

            // 날짜를 하나 추가하여 재탐색
            if (map[nextY][nextX] == 0)
            {
                q.push(make_pair(nextX, nextY));
                map[nextY][nextX] = map[y][x] + 1;
            }
        }
    }
}

int solution(int m, int n)
{
    int x, y, ans = 0;

    // 모든 정점에 대해 토마토가 익기까지 날짜를 계산한다
    SimultaneousBfs(m, n);
    
    // 토마토가 모두 익기 위해 필요한 최소 날짜를 구한다
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= m; x++)
        {
            // 토마토가 안 익어 있을 경우 -1을 출력
            if (map[y][x] == 0)
            {
                return -1;
            }

            ans = MAX(ans, map[y][x] - 1);
        }
    }

    return ans;
}

int main()
{
    int m, n, x, y;
    // 그래프 생성
    scanf("%d %d", &m, &n);

    memset(map, -1, sizeof(map));
    
    for (y = 1; y <= n; y++) // y : n
    {
        for (x = 1; x <= m; x++) // x : m
        {
            scanf("%d", &map[y][x]);
        }
    }

    printf("%d\n", solution(m, n));

    return 0;
}