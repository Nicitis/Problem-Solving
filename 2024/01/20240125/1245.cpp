#include <iostream>
#include <cstring>

using namespace std;

int height[100][70];
bool visit[100][70];

// dfs 방식으로 산봉우리인지 검사
bool isPeak(int row, int col, int N, int M)
{
    bool result = true;
    visit[row][col] = true;

    for (int dir = 0; dir < 9; dir++)
    {
        int nextrow = row + (dir / 3 - 1);
        int nextcol = col + (dir % 3 - 1);

        if (nextrow < 0 || nextrow >= N ||
            nextcol < 0 || nextcol >= M)
            continue;

        // 같은 높이면 탐색
        if (height[row][col] == height[nextrow][nextcol])
        {
            // 봉우리인지 탐색하기
            if (visit[nextrow][nextcol] == false &&
                isPeak(nextrow, nextcol, N, M) == false)
                result = false;
        }
        // 더 높은 격자를 발견하면 봉우리가 아님
        else if (height[row][col] < height[nextrow][nextcol])
            result = false;
    }

    return result;
}

int solve(int N, int M)
{
    int peak = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visit[i][j])
                continue;
            
            if (isPeak(i, j, N, M))
                peak++;
        }
    }
    return peak;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    int N, M;
    memset(visit, (bool)false, sizeof(visit));

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> height[i][j];

    cout << solve(N, M) << '\n';

    return 0;
}