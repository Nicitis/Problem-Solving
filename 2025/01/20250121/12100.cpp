#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int biggestNode = 1;

// void PrintBoard(const vector<vector<int>>& board)
// {
//     cout << "===current board===\n";
//     int maximum = 0;
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board.size(); j++)
//         {
//             cout << board[i][j] << " ";
//             if (board[i][j] > maximum)
//                 maximum = board[i][j];
//         }
//         cout << '\n';
//     }
//     cout << "(maximum = " << maximum << ")\n";
// }

bool TryMove(const vector<vector<int>>& board, int dx, int dy, vector<vector<int>>& outBoard)
{
    stack<int> nodestack;
    bool moveable = false;
    outBoard.assign(board.size(), vector<int>(board.size(), 0));
    // horizontal
    if (dy == 0)
    {
        // 오른쪽 움직임일 땐 오른쪽부터, 왼쪽 움직임일 땐 왼쪽부터 검사
        for (int i = 0; i < board.size(); i++)
        {
            bool empty = false;
            
            int sj = dx > 0 ? board.size() - 1 : 0;
            int numNodes = 0;
            for (int j = sj; j >= 0 && j < board.size(); j -= dx)
            {
                if (board[i][j] == 0)
                    empty = true;
                else
                {
                    if (!nodestack.empty() && board[i][j] == nodestack.top())
                    {
                        // merge
                        nodestack.pop();
                        nodestack.push(board[i][j] * 2);
                        moveable = true;
                        if (nodestack.top() > biggestNode)
                            biggestNode = board[i][j] * 2;
                        // 이미 합친 곳은 다시 합치지 않도록 0을 넣어준다.
                        nodestack.push(0);
                    }
                    else
                    {
                        if (empty)
                            moveable = true;
                        nodestack.push(board[i][j]);
                        numNodes++;
                    }
                }
            }
            
            sj = dx > 0 ? board.size() - numNodes : numNodes - 1;
            for (int j = sj; !nodestack.empty(); j += dx)
            {
                if (nodestack.top() == 0)
                    nodestack.pop();
                outBoard[i][j] = nodestack.top();
                nodestack.pop();
            }
        }
    }
    // vertical
    else
    {
        outBoard.assign(board.size(), vector<int>());
        // 위쪽 움직임일 땐 위부터, 아래쪽 움직임일 땐 아래부터 검사
        for (int j = 0; j < board.size(); j++)
        {
            bool empty = false;
            
            int si = dy > 0 ? board.size() - 1 : 0;
            int numNodes = 0;
            for (int i = si; i >= 0 && i < board.size(); i -= dy)
            {
                if (board[i][j] == 0)
                    empty = true;
                else
                {
                    if (!nodestack.empty() && board[i][j] == nodestack.top())
                    {
                        // merge
                        nodestack.pop();
                        nodestack.push(board[i][j] * 2);
                        moveable = true;
                        if (nodestack.top() > biggestNode)
                            biggestNode = board[i][j] * 2;
                        // 이미 합친 곳은 다시 합치지 않도록 0을 넣어준다.
                        nodestack.push(0);
                    }
                    else
                    {
                        if (empty)
                            moveable = true;
                        nodestack.push(board[i][j]);
                        numNodes++;
                    }
                }
            }

            si = dy > 0 ? board.size() - numNodes : numNodes - 1;
            for (int i = si; !nodestack.empty(); i += dy)
            {
                while (nodestack.top() == 0)
                    nodestack.pop();
                outBoard[i][j] = nodestack.top();
                nodestack.pop();
            }
        }
    }
    return moveable;
}

void Search(vector<vector<int>>& board, int depth)
{
    // PrintBoard(board);
    if (depth <= 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> nextBoard;
        if (TryMove(board, dx[i], dy[i], nextBoard))
        {
            Search(nextBoard, depth - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> board[i][j];
            if (board[i][j] > biggestNode)
                biggestNode = board[i][j];
        }
    }
    Search(board, 5);
    
    cout << biggestNode << '\n';
    
    return 0;
}