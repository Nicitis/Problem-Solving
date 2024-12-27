#include <cstdio>

int invalidArea(char board[50][51], int row, int col)
{
    // 8*8 영역에 대해 잘못 칠해진 사각형의 최솟값을 계산합니다.
    int squares = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            squares += (row + i + col + j) % 2 == 0 ?
                board[row + i][col + j] == 'W' : board[row + i][col + j] == 'B';
        }
    }
    if (squares > 8 * 8 - squares)
        squares = 8 * 8 - squares;
    return squares;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    // 적분 배열 생성
    char board[50][51]; // (N+1)*(M+1), 첫 칸은 0

    for (int i = 0; i < N; i++)
    {
        scanf("%s", board[i]);
    }

    int minSquares = 100;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int area = invalidArea(board, i, j);
            if (area < minSquares)
                minSquares = area;
        }
    }
    printf("%d\n", minSquares);
}