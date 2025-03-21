#include <iostream>
#include <string>
#include <queue>

#define PairInt pair<int, int>

using namespace std;

struct CaseNode
{
    int movements;
    PairInt redPos;
    PairInt bluePos;

    CaseNode(int inMovements, PairInt inRedPos, PairInt inBluePos)
        : movements(inMovements)
        , redPos(inRedPos)
        , bluePos(inBluePos)
    {}
};

bool TryMove(PairInt startPoint, int dx, int dy, string map[], PairInt& out)
{
    bool success = false;
    int y = startPoint.first;
    int x = startPoint.second;

    while (map[y+dy][x+dx] == '.' || map[y+dy][x+dx] == 'O')
    {
        y += dy;
        x += dx;
        if (map[y][x] == 'O')
        {
            success = true;
            break;
        }
    }
    out = make_pair(y, x);
    return success;
}

bool IsRedFirst(PairInt redPos, PairInt bluePos, int dx, int dy)
{
    if (dx == 0)
    {
        if (redPos.first < bluePos.first)
            return dy < 0;
        else
            return dy > 0;
    }
    else
    {
        if (redPos.second < bluePos.second)
            return dx < 0;
        else
            return dx > 0;
    }
}

int main()
{
    int n, m;
    string map[10];
    queue<CaseNode> q;
    int dy[] = { -1, 0, 0, 1 };
    int dx[] = { 0, -1, 1, 0 };
    
    PairInt redPos, bluePos;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'R')
                redPos = make_pair(i, j);
            else if (map[i][j] == 'B')
                bluePos = make_pair(i, j);
        }
    }

    q.push(CaseNode(0, redPos, bluePos));

    map[redPos.first][redPos.second] = '.';
    map[bluePos.first][bluePos.second] = '.';

    while (!q.empty())
    {
        CaseNode cur = q.front();
        q.pop();
        if (cur.movements >= 10)
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            bool success = false;
            if (IsRedFirst(cur.redPos, cur.bluePos, dx[dir], dy[dir]))
            {
                // move red ball
                if (TryMove(cur.redPos, dx[dir], dy[dir], map, redPos))
                {
                    success = true;
                }

                if (map[redPos.first][redPos.second] == '.')
                    map[redPos.first][redPos.second] = 'R';

                // move blue ball
                if (TryMove(cur.bluePos, dx[dir], dy[dir], map, bluePos))
                {
                    if (map[redPos.first][redPos.second] == 'R')
                        map[redPos.first][redPos.second] = '.';
                    continue; // Fail
                }
                
                if (map[redPos.first][redPos.second] == 'R')
                        map[redPos.first][redPos.second] = '.';

                if (cur.redPos == redPos && cur.bluePos == bluePos)
                    continue;

                // 빨강 공만 들어갔을 경우 성공
                if (success)
                {
                    cout << cur.movements + 1 << "\n";
                    return 0;
                }
                
                q.push(CaseNode(cur.movements + 1, redPos, bluePos));
            }
            else
            {
                // move blue ball
                if (TryMove(cur.bluePos, dx[dir], dy[dir], map, bluePos))
                    continue; // Fail

                if (map[bluePos.first][bluePos.second] == '.')
                    map[bluePos.first][bluePos.second] = 'B';
                
                // move red ball
                if (TryMove(cur.redPos, dx[dir], dy[dir], map, redPos))
                {
                    cout << cur.movements + 1 << "\n";
                    return 0;
                }
                if (map[bluePos.first][bluePos.second] == 'B')
                    map[bluePos.first][bluePos.second] = '.';

                if (cur.redPos == redPos && cur.bluePos == bluePos)
                    continue;

                q.push(CaseNode(cur.movements + 1, redPos, bluePos));
            }
        }
    }
    cout << "-1\n";

    return 0;
}