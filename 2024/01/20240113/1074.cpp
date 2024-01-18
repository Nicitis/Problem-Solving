#include <iostream>
#include <cmath>

using namespace std;

int NumberOfVisit(int r, int c, int minRow, int minCol, int maxRow, int maxCol)
{
    int visit = 0;
    int midRow = (minRow + maxRow) / 2;
    int midCol = (minCol + maxCol) / 2;
    int quarterArea = (midRow - minRow + 1) * (midCol - minCol + 1);

    if (minRow == maxRow) // 종료 조건
        return 0;

    if (r <= midRow) // up
    {
        maxRow = midRow;
        if (c <= midCol) // left up
        {
            maxCol = midCol;
            visit = 0;
        }
        else // right up
        {
            minCol = midCol + 1;
            visit = quarterArea;
        }
    }
    else // down
    {
        minRow = midRow + 1;
        if (c <= midCol) // left down
        {
            maxCol = midCol;
            visit = quarterArea * 2;
        }
        else // right down
        {
            minCol = midCol + 1;
            visit = quarterArea * 3;
        }
    }
    return visit + NumberOfVisit(r, c, minRow, minCol, maxRow, maxCol);
}

int main()
{
    int n, r, c;
    int size;

    cin >> n >> r >> c;

    size = pow(2, n);

    cout << NumberOfVisit(r, c, 0, 0, size - 1, size - 1);

    return 0;
}