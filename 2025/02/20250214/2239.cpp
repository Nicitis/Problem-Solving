#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int check_horizontal[9] = { 0 };
int check_vertical[9] = { 0 };
int check_box[9] = { 0 };

string board[9];

int get_box_idx(int row, int col)
{
    return (row / 3 * 3) + col / 3;
}

void initialize_check()
{
    int num;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            num = board[i][j] - '0';
            if (num == 0)
                continue;
            check_horizontal[i] |= (1 << num);
            check_vertical[j] |= (1 << num);
            check_box[get_box_idx(i, j)] |= (1 << num);
        }
    }
}

bool solve_sudoku(int row, int col)
{
    // find next blank
    bool findNext = false;
    for (; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == '0')
            {
                findNext = true;
                break;
            }
        }
        if (findNext)
            break;
    }
    if (!findNext)
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (check_horizontal[row] & (1 << num))
            continue;
        if (check_vertical[col] & (1 << num))
            continue;
        if (check_box[get_box_idx(row, col)] & (1 << num))
            continue;
        
        check_horizontal[row] |= (1 << num);
        check_vertical[col] |= (1 << num);
        check_box[get_box_idx(row, col)] |= (1 << num);

        board[row][col] = ('0' + num);

        if (solve_sudoku(row, col))
            return true;
        
        board[row][col] = '0';

        check_horizontal[row] &= ~(1 << num);
        check_vertical[col] &= ~(1 << num);
        check_box[get_box_idx(row, col)] &= ~(1 << num);
    }
    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
        cin >> board[i];
    
    initialize_check();
    solve_sudoku(0, 0);

    for (int i = 0; i < 9; i++)
    {
        cout << board[i] << '\n';
    }

    return 0;
}