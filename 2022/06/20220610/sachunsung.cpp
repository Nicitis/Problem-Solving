#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#include <iostream>

using namespace std;

// 이미 지운 노드는 _로 표시

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };
bool visit[100][100];

void print(vector<string>& board)
{
    for (int i = 0; i < board.size(); i++)
        cout << board[i] << '\n';
}

// dfs : 보드, 방향, 꺾을 수 있는 횟수, 위치 -> bool 
bool dfs(vector<string>& board, int row, int column, int direction, bool turnable, char tile)
{
    bool check = false;
    if (board[row][column] == tile)
    {
        return true;
    }

    visit[row][column] = true;
    
    
    for (int i = 0; i < 4; i++)
    {
        int x = column + dx[i];
        int y = row + dy[i];
        if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
            continue;
        if (visit[y][x])
            continue;
        if (i == direction)
        {
            if (board[y][x] != '.' && board[y][x] != tile)
                continue;
            if (dfs(board, y, x, i, turnable, tile))
            {
                check = true;
                break;
            }
        }
        else if (turnable)
        {
            if (board[y][x] != '.' && board[y][x] != tile)
                continue;
            if (dfs(board, y, x, i, false, tile))
            {
                check = true;
                break;
            }
        }
    }
    
    visit[row][column] = false;
    
    return check;
}

bool CanErase(vector<string>& board, int row, int column)
{
    char c = board[row][column];
    bool check = false;
    visit[row][column] = true;
    // 사방향으로 살펴보기
    for (int i = 0; i < 4; i++)
    {
        int x = column + dx[i];
        int y = row + dy[i];
        if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
            continue;
        if (board[y][x] != '.' && board[y][x] != c)
            continue;

        if (dfs(board, y, x, i, true, c))
        {
            check = true;
            break;
        }
            
    }
    visit[row][column] = false;
    return check;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<char> candidate; // 일단 이건 나중에 해보기
    bool check;
    
    print(board);
    
    do
    {
        // 하나라도 제거하는 데에 성공하면 다시 시작
        // 빈칸(.)은 취급 x
        // 모든 칸 다 탐색해보기;
        check = false;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                char tile = board[r][c];
                if (board[r][c] == '*' || board[r][c] == '.')
                    continue;
                if (CanErase(board, r, c))
                {
                    candidate.push_back(tile);
                    check = true;
                }
            }
        }
        
        if (check)
        {
            // 다 하고 나면 candidate 정렬
            stable_sort(candidate.begin(), candidate.end());
            char target = candidate[0];
            answer += target;

            candidate.clear();

            // 지울 대상을 찾아 .로 바꾼다.
            for (int r = 0; r < m; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (board[r][c] == target)
                        board[r][c] = '.';
                }
            }
        }
    }
    while (check);

    // 모두 지우는 데에 성공했는가?
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
            if (board[r][c] != '.' && board[r][c] != '*')
            {
                return "IMPOSSIBLE";
            }
    }
    
    return answer;
}

int main()
{
    vector<string> board = {"DBA", "C*A", "CDB"};

    cout << solution(board.size(), board[0].size(), board);

    return 0;
}