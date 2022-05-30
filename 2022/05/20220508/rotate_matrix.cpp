#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

void print(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===========\n";
}

int RotateAndGetMinimal(vector<vector<int>>& matrix, int minrow, int mincol, int maxrow, int maxcol)
{
    int minval = matrix[minrow][mincol];
    
    int row = minrow;
    int col = mincol;
    int prev = matrix[minrow][mincol];
    matrix[minrow][mincol] = matrix[minrow + 1][mincol];
    
    while (col < maxcol)
    {
        int temp = matrix[row][col + 1];
        matrix[row][col + 1] = prev;
        prev = temp;
        col++;
        minval = min(minval, prev);
    }
    
    while (row < maxrow)
    {
        int temp = matrix[row + 1][col];
        matrix[row + 1][col] = prev;
        prev = temp;
        row++;
        minval = min(minval, prev);
    }
    
    while (col > mincol)
    {
        int temp = matrix[row][col - 1];
        matrix[row][col - 1] = prev;
        prev = temp;
        col--;
        minval = min(minval, prev);
    }
    
    while (row > minrow)
    {
        int temp = matrix[row - 1][col];
        matrix[row - 1][col] = prev;
        prev = temp;
        row--;
        minval = min(minval, prev);
    }
    
    return minval;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    
    int number = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = number++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int minimal = RotateAndGetMinimal(matrix, queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        cout << minimal << '\n';
        answer.push_back(minimal);
    }
    
    return answer;
}

int main()
{
    int rows, cols, n;
    vector<vector<int>> queries(n, vector<int>());
    cin >> n;
    cin >> rows >> cols;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int k;
            cin >> k;
            queries[i].push_back(k);
        }
    }

    vector<int> sol = solution(rows, cols, queries);

    cout << "size = " << sol.size() << '\n';
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << ' ';
    }

    return 0;
}