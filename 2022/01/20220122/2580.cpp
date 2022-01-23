// 백준 2580: 스도쿠(C++)
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<pair<int, int>> blankList; // 앞으로 채워야 할 0의 위치
int map[9][9]; // 스도쿠 맵

void PickCandidate(int row, int col, bool candidate[])
{
    // 3*3 확인
    int r, c, r1, c1, r2, c2;
    r1 = (row / 3) * 3;
    c1 = (col / 3) * 3;
    r2 = r1 + 3;
    c2 = c1 + 3;

    for (r = r1; r < r2; r++)
    {
        for (c = c1; c < c2; c++)
        {
            candidate[map[r][c]] = false;
        }
    }

    // 가로 체크
    r = row;
    for (c = 0; c < 9; c++)
    {
        candidate[map[r][c]] = false;
    }
    
    // 세로 체크
    c = col;
    for (r = 0; r < 9; r++)
    {
        candidate[map[r][c]] = false;
    }
}

bool TrySudoku(int blankIdx, int numberOfBlank)
{
    int r, c;

    if (blankIdx == numberOfBlank)
        return true;

    // 모든 값을 시도해본다.
    auto blank = blankList[blankIdx];

    // 후보를 선정한다.
    bool candidate[10];
    memset(candidate, true, sizeof(candidate));
    PickCandidate(blank.first, blank.second, candidate);
    
    for (int i = 1; i <= 9; i++)
    {
        if (candidate[i] == false)
            continue;

        map[blank.first][blank.second] = i;
        if (TrySudoku(blankIdx + 1, numberOfBlank))
            return true;
    }
    map[blank.first][blank.second] = 0;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0) // 0의 위치 추가
                blankList.push_back(make_pair(i, j));
        }
    }

    TrySudoku(0, blankList.size());

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}