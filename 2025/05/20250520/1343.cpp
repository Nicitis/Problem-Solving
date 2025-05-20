#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string board;
    cin >> board;

    int numB = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (numB == 4)
        {
            board[i-4] = board[i-3] = board[i-2] = board[i-1] = 'A';
            numB = 0;
        }
        if (board[i] == '.')
        {
            numB = 0;
            continue;
        }
        else if (i + 1 < board.size() && board[i] == 'X' && board[i+1] == 'X')
        {
            board[i] = board[i + 1] = 'B';
            i++;
            numB += 2;
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
    int i = board.size();
    if (numB == 4)
    {
        board[i-4] = board[i-3] = board[i-2] = board[i-1] = 'A';
        numB = 0;
    }
    cout << board;

    return 0;
}