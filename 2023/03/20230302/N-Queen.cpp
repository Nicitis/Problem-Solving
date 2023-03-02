#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printBoard(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            cout << board[i][j];
        cout << endl;
    }
}

void TrySetBoard(int value, int row, int col, vector<vector<bool>>& refBoard)
{
    if (row < 0 || row >= refBoard.size() ||
        col < 0 || col >= refBoard.size())
        return;
    
    refBoard[row][col] = value;
}

int getNQueen(int col, vector<vector<bool>> board)
{
    // 종료 조건: 끝에 도달했거나, 다음 자리에 배치할 게 없을 때
    if (col == board.size())
        return 1;
    
    int cases = 0;
    
    for (int r = 0; r < board.size(); r++)
    {
        if (board[r][col] == true)
        {
            vector<vector<bool>> nextBoard(board);
            // (r, col) 자리에 퀸을 배치하고, 퀸을 배치할 수 없는 자리를 설정해준다.
            nextBoard[r][col] = false;
            // 가로 및 세로
            for (int i = 0; i < board.size(); i++)
            {
                nextBoard[i][col] = false;
                nextBoard[r][i] = false;
                // 좌상단-우하단 대각선
                TrySetBoard(false, r-i, col-i, nextBoard);
                TrySetBoard(false, r+i, col+i, nextBoard);
                // 좌하단-우상단 대각선
                TrySetBoard(false, r+i, col-i, nextBoard);
                TrySetBoard(false, r-i, col+i, nextBoard);
            }
            // cout << r << ", " << col << endl;
            // printBoard(nextBoard);
            
            cases += getNQueen(col + 1, nextBoard);
        }
    }
    return cases;
}

// 백트래킹 알고리즘으로 가능성 없는 경우를 제외한다.
int solution(int n) {
    vector<vector<bool>> availableBoard(n, vector<bool>(n, true));

    return getNQueen(0, availableBoard);
}

int main()
{
    int n;
    cout << "input N: ";
    cin >> n;
    cout << solution(n) << endl;

    return 0;
}