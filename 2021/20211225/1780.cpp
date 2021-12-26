// 백준 1780: 종이의 개수(c++)
#include <iostream>
#include <vector>

using namespace std;

int numberOfMinus1, numberOf0, numberOf1;

// 종이 안의 모든 숫자가 모두 동일한지 확인한다.
bool HasEqualNumbers(int row, int col, int size, const vector<vector<int>>& matrix)
{
    if (size == 1)
        return true;
    
    int value = matrix[row][col];

    for (int currRow = row; currRow < row + size; currRow++)
    {
        for (int currCol = col; currCol < col + size; currCol++)
        {
            if (matrix[currRow][currCol] != value)
                return false;
        }
    }
    return true;
}

// 종이를 9장으로 나누어가며 같은 숫자가 적힌 종이가 숫자별로 몇 장인지 계산한다.
void DivideBy9(int row, int col, int size, const vector<vector<int>>& matrix)
{
    // 모두 동일한지 확인한다.
    if (HasEqualNumbers(row, col, size, matrix))
    {
        if (matrix[row][col] == -1) numberOfMinus1++;
        else if (matrix[row][col] == 0) numberOf0++;
        else numberOf1++;

        return;
    }
    
    int nextSize = size / 3;
    for (int currRow = row; currRow < row + size; currRow += nextSize)
    {
        for (int currCol = col; currCol < col + size; currCol += nextSize)
        {
            DivideBy9(currRow, currCol, nextSize, matrix);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    vector<vector<int>> numberMatrix(n, vector<int>(n, 0));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> numberMatrix[row][col];
        }
    }

    DivideBy9(0, 0, n, numberMatrix);

    cout << numberOfMinus1 << '\n';
    cout << numberOf0 << '\n';
    cout << numberOf1;

    return 0;    
}