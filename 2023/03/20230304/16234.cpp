// 2023.03.04., 백준 16234 인구 이동, https://www.acmicpc.net/problem/16234
#include <iostream>
#include <vector>

#define UNDEF -1

using namespace std;

int xdir[] = { 0, -1, 1, 0 };
int ydir[] = { -1, 0, 0, 1 };

bool CanOpenBoundary(int a, int b, int minimum, int maximum)
{
    int delta = abs(a - b);

    return minimum <= delta && delta <= maximum;
}

int GetUnionNumber(int x, int y, int n)
{
    return y * n + x;
}

// 국경을 열어 연합을 만든다. 해당 국가가 속하는 연합의 인구수를 반환한다.
int OpenBoundaries(const vector<vector<int>>& nations, vector<vector<int>>& unions, vector<int>& unionCount, int x, int y, int n, int min, int max)
{
    int people = nations[y][x];
    // 연합 번호가 설정되지 않았다면 자기 국가 번호를 기록하여 방문했음을 기록한다.
    if (unions[y][x] == UNDEF)
        unions[y][x] = GetUnionNumber(x, y, n);

    unionCount[unions[y][x]]++;

    for (int dir = 0; dir < 4; dir++)
    {
        int nextX = x + xdir[dir];
        int nextY = y + ydir[dir];

        if (nextX < 0 || nextX >= n ||
            nextY < 0 || nextY >= n)
            continue;
        
        if (unions[nextY][nextX] == UNDEF &&
            CanOpenBoundary(nations[y][x], nations[nextY][nextX], min, max))
        {
            unions[nextY][nextX] = unions[y][x];
            people += 
                OpenBoundaries(nations, unions, unionCount, nextX, nextY, n, min, max);
        }
    }

    return people;
}

bool TryShifting(vector<vector<int>>& nations, int n, int min, int max)
{
    bool isMoved = false;

    vector<vector<int>> unions(n, vector<int>(n, UNDEF));
    // 각 국가가 속한 연합 번호. 연합 번호는 row * n + col로 기록한다.
    vector<int> people(n*n, 0); // 연합별 인구수.
    vector<int> unionCount(n*n, 0); // 연합별 소속 국가 수

    // 연합 및 인구수를 기록한다.
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (unions[r][c] != UNDEF)
                continue;

            people[GetUnionNumber(c, r, n)] = 
                OpenBoundaries(nations, unions, unionCount, c, r, n, min, max);
        }
    }

    // 연합별 평균 인구수를 기록한다.
    for (int i = 0; i < n*n; i++)
    {
        if (unionCount[i] != 0)
            people[i] = people[i] / unionCount[i];
    }

    // 인구 이동을 실시한다.
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (unions[r][c] != GetUnionNumber(c, r, n))
            {
                isMoved = true;
            }
            nations[r][c] = people[unions[r][c]];
        }
    }

    return isMoved;
}

int main(void)
{
    int n, l, r, days = 0;
    bool isMoved;

    cin >> n >> l >> r;

    vector<vector<int>> nations(n, vector<int>(n, 0));

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> nations[r][c];

    do
    {
        isMoved = TryShifting(nations, n, l, r);
        if (isMoved)
            days++;
    } while (isMoved);

    cout << days << endl;

    return 0;
}