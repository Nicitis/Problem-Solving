#include <iostream>

#define LINES 7

using namespace std;

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

int main()
{
    string map[LINES];
    int answer = 0;

    for (int i = 0; i < LINES; i++)
    {
        getline(cin, map[i]);
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] != '.')
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int row = i + dy[dir];
                int col = j + dx[dir];
                if (row < 0 || row >= LINES ||
                    col < 0 || col >= map[i].size() ||
                    map[row][col] != 'o')
                    continue;
                int jumpedRow = row + dy[dir];
                int jumpedCol = col + dx[dir];
                if (jumpedRow < 0 || jumpedRow >= LINES ||
                    jumpedCol < 0 || jumpedCol >= map[i].size() ||
                    map[jumpedRow][jumpedCol] != 'o')
                    continue;
                answer++;
            }
        }
    }
    
    cout << answer << '\n';

    return 0;
}