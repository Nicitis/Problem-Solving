// 2023.09.19., 백준 1080 행렬, https://www.acmicpc.net/problem/1080
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Flip(vector<string>& matrix, int row, int col)
{
    for (int r = row; r < row + 3; r++)
    {
        for (int c = col; c < col + 3; c++)
        {
            if (matrix[r][c] == '0')
                matrix[r][c] = '1';
            else
                matrix[r][c] = '0';
        }
    }
}

bool IsEqualMatrix(vector<string>& A, vector<string>& B, int n, int m)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (A[r][c] != B[r][c])
                return false;
        }
    }
    return true;
}

int NumberOfFlips(vector<string>& A, vector<string>& B, int n, int m)
{
    int cnt = 0;

    if (n <= 3 && m <= 3)
    {
        if (IsEqualMatrix(A, B, n, m))
            return 0;
        // n과 m이 3*3이 아니라면, 뒤집을 수 없으므로 -1 반환
        if (!(n == 3 && m == 3))
        {
            return -1;
        }
    }

    for (int r = 0; r < n - 2; r++)
    {
        for (int c = 0; c < m - 2; c++)
        {
            if (A[r][c] != B[r][c])
            {
                Flip(A, r, c);
                cnt++;
            }
        }
    }

    // 뒤집을 수 있는 대로 모두 뒤집었는데도 A와 B가 다르면 -1
    if (!IsEqualMatrix(A, B, n, m))
        return -1;

    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> A(n, ""), B(n, "");

    for (int r = 0; r < n; r++)
        cin >> A[r];

    for (int r = 0; r < n; r++)
        cin >> B[r];

    cout << NumberOfFlips(A, B, n, m) << '\n';

    return 0;
}