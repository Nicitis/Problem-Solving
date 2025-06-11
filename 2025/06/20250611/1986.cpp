#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<bool>> safeBoard;
vector<vector<bool>> objBoard;

inline bool isInMap(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void checkQueen(int r, int c)
{
    safeBoard[r][c] = false;
    // row
    for (int nextC = c - 1; nextC >= 0; nextC--)
    {
        if (objBoard[r][nextC])
            break;
        safeBoard[r][nextC] = false;
    }
    for (int nextC = c + 1; nextC < m; nextC++)
    {
        if (objBoard[r][nextC])
            break;
        safeBoard[r][nextC] = false;
    }
    // col
    for (int nextR = r - 1; nextR >= 0; nextR--)
    {
        if (objBoard[nextR][c])
            break;
        safeBoard[nextR][c] = false;
    }
    for (int nextR = r + 1; nextR < n; nextR++)
    {
        if (objBoard[nextR][c])
            break;
        safeBoard[nextR][c] = false;
    }
    
    // left-up to right-down
    int minDist = min(r, c);
    for (int j = 1; j <= minDist; j++)
    {
        if (objBoard[r - j][c - j])
            break;
        safeBoard[r - j][c - j] = false;
    }
    
    minDist = min(n - r - 1, m - c - 1);
    for (int j = 1; j <= minDist; j++)
    {
        if (objBoard[r + j][c + j])
            break;
        safeBoard[r + j][c + j] = false;
    }

    // right-up to leftdown
    minDist = min(r, m - c - 1);
    for (int j = 1; j <= minDist; j++)
    {
        if (objBoard[r - j][c + j])
            break;
        safeBoard[r - j][c + j] = false;
    }

    minDist = min(n - r - 1, c);
    for (int j = 1; j <= minDist; j++)
    {
        if (objBoard[r + j][c - j])
            break;
        safeBoard[r + j][c - j] = false;
    }
}

// 나이트 이동 맵
int dr[2] = { 1, 2 };
int dc[2] = { 2, 1 };
// 좌상-우상-좌하-우하에 대한 방향
int signR[4] = { -1, -1, 1, 1 };
int signC[4] = { -1, 1, -1, 1 };

void checkKnight(int r, int c)
{
    safeBoard[r][c] = false;
    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 0; i < 2; i++)
        {
            int nextR = r + signR[dir] * dr[i];
            int nextC = c + signC[dir] * dc[i];
            if (isInMap(nextR, nextC))
            {
                safeBoard[nextR][nextC] = false;
            }
        }
    }
}

int main()
{
    int k, r, c;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    safeBoard = vector<vector<bool>>(n, vector<bool>(m, true));
    objBoard = vector<vector<bool>>(n, vector<bool>(m, false));

    vector<pair<int, int>> queenPositions;

    // queen
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        objBoard[r - 1][c - 1] = true;
        queenPositions.push_back({r - 1, c - 1});// 0, 0을 기준으로 좌표 수정
    }

    // knight
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        objBoard[r - 1][c - 1] = true;
        checkKnight(r - 1, c - 1);
    }

    // pawn
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        objBoard[r - 1][c - 1] = true;
        safeBoard[r - 1][c - 1] = false;
    }

    for (const pair<int, int>& p : queenPositions)
    {
        checkQueen(p.first, p.second);
    }

    int safeArea = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (safeBoard[r][c])
                safeArea++;
        }
    }

    cout << safeArea;

    return 0;
}