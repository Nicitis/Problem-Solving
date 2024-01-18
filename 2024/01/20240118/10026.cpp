#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visit;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void print(vector<string>& grid)
{
    for (int i = 0; i < grid.size(); i++)
        cout << grid[i] << '\n';
}

void dfs(vector<string>& grid, int N, int row, int col)
{
    visit[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextrow = row + dy[i];
        int nextcol = col + dx[i];

        if (nextrow < 0 || nextrow >= N ||
            nextcol < 0 || nextcol >= N)
            continue;

        if (!visit[nextrow][nextcol] && 
            grid[row][col] == grid[nextrow][nextcol])
            dfs(grid, N, nextrow, nextcol);
    }
}

int main()
{
    int N, normal_area, blind_area;
    string s;
    cin >> N;

    normal_area = 0;
    blind_area = 0;

    vector<string> grid;
    visit = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        grid.push_back(s);
    }

    // normal area
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
                continue;
            
            dfs(grid, N, i, j);
            normal_area++;
        }
    }

    // color blindness area
    visit = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'G')
                grid[i][j] = 'R';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
                continue;
            
            dfs(grid, N, i, j);
            blind_area++;
        }
    }

    cout << normal_area << " " << blind_area << '\n';

    return 0;
}