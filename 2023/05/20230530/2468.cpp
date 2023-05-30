// 2023.05.30., 백준 2468 안전 영역, https://www.acmicpc.net/problem/2468
// 해결 전략: 높이별 설정->dfs 통한 CC(connected component) 개수 찾기
#include <cstdio>
#include <cstring>

bool visit[100][100];
int heights[100][100];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void dfs(int x, int y, int h, int n)
{
    int nx, ny;
    visit[y][x] = true;
    
    for (int dir = 0; dir < 4; dir++)
    {
        nx = x + dx[dir];
        ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        
        if (!visit[ny][nx] && heights[ny][nx] > h)
            dfs(nx, ny, h, n);
    }
}

int main(void)
{
    int n, r, c;
    scanf("%d", &n);
    for (r = 0; r < n; r++)
        for (c = 0; c < n; c++)
            scanf("%d", &heights[r][c]);

    int max_cc = 1;
    for (int h = 1; h < 100; h++)
    {
        // 초기화
        int cc = 0;
        memset(visit, 0, 100 * 100 * sizeof(bool));
        
        for (r = 0; r < n; r++)
        {
            for (c = 0; c < n; c++)
            {
                if (!visit[r][c] && heights[r][c] > h)
                {
                    cc++;
                    dfs(c, r, h, n);
                }
            }
        }

        if (cc == 0) // 안전 영역이 없을 경우 종료
            break;

        max_cc = cc > max_cc ? cc : max_cc;
    }

    printf("%d", max_cc);

    return 0;
}