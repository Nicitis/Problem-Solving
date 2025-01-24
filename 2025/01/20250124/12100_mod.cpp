#include <iostream>
#include <cstring>
#include <string>
#include <queue>

struct Board
{
    int board[20][20];
    int tempBoard[20][20];
    int maxBlock;
    int N;

    Board(int newBoard[20][20], int newN)
    {
        memcpy(board, newBoard, sizeof(board));
        N = newN;
        maxBlock = 0;
    }

    void Rotate()
    {
        memcpy(tempBoard, board, sizeof(board));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = tempBoard[j][N-1-i];
            }
        }
    }

    bool PushUp()
    {
        std::deque<int> deq;
        bool success = false;
        for (int col = 0; col < N; col++)
        {
            bool empty = false;
            bool merged = false;
            for (int row = 0; row < N; row++)
            {
                if (board[row][col] == 0)
                {
                    empty = true;
                }
                else if (!merged && !deq.empty() && deq.back() == board[row][col])
                {
                    merged = true;
                    success = true;
                    deq.pop_back();
                    deq.push_back(board[row][col] * 2);
                    if (deq.back() > maxBlock)
                        maxBlock = deq.back();
                }
                else
                {
                    merged = false;
                    deq.push_back(board[row][col]);
                    if (empty)
                        success = true;
                    if (board[row][col] > maxBlock)
                        maxBlock = board[row][col];
                }
            }

            for (int row = 0; row < N; row++)
            {
                if (!deq.empty())
                {
                    board[row][col] = deq.front();
                    deq.pop_front();
                }
                else
                    board[row][col] = 0;
            }
        }
        return success;
    }
};

int Search(Board& board, int depth)
{
    if (depth == 0)
    {
        return board.maxBlock;
    }

    int maxBlock = 0, block;

    for (int i = 0; i < 4; i++)
    {
        board.Rotate();

        Board nextBoard(board.board, board.N);
        if (nextBoard.PushUp())
        {
            block = Search(nextBoard, depth - 1);
        }
        else
        {
            block = nextBoard.maxBlock;
        }
        if (block > maxBlock)
            maxBlock = block;
    }
    return maxBlock;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int board[20][20];
    
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> board[i][j];
        }
    }

    Board initialBoard(board, N);
    std::cout << Search(initialBoard, 5) << '\n';
    

    return 0;
}