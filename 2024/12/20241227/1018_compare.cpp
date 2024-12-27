#include <cstdio>
#include <ctime>

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

int solvedByBrute(char board[50][51], int N, int M)
{
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
    return minSquares;
}

int solvedByIntegral(char board[50][51], int N, int M)
{
    // 적분 배열 생성
    int sumBoard[51][51]; // (N+1)*(M+1), 첫 칸은 0

    // 초기화
    for (int i = 0; i <= N; i++)
        for (int j = 0; j < M; j++)
            sumBoard[i][j] = 0;

    for (int row = 1; row <= N; row++)
    {
        int accSquares = 0;
        for (int col = 1; col <= M; col++)
        {
            // 좌상단이 흑색이라 가정하고, 좌측 위부터 현재 노드까지 직사각형 범위에서 다시 칠해야 하는 사각형 합을 구함
            accSquares += ((row + col) % 2 == 0) ?
                board[row - 1][col - 1] == 'W' : board[row - 1][col - 1] == 'B';
            sumBoard[row][col] = sumBoard[row-1][col] + accSquares;
        }
    }

    // 8x8 보드를 순회하며 다시 칠해야 할 사각형의 최소 개수 구하기
    int minSquares = 8*8;
    for (int row = 8; row <= N; row++)
    {
        for (int col = 8; col <= M; col++)
        {
            // A - B
            // |   |
            // C - D
            // 에 대하여 ABCD 범위의 합은 (D + A - B - C)
            int squares = sumBoard[row][col] 
                + sumBoard[row - 8][col - 8]
                - sumBoard[row - 8][col]
                - sumBoard[row][col - 8];
            if (squares > 8 * 8 - squares)
                squares = 8 * 8 - squares; // 처음을 흰색으로 칠할 때 개수
            if (minSquares > squares)
                minSquares = squares;
        }
    }
    return minSquares;
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

    clock_t start, finish;
    const int repeat = 100000;
    int resultA, resultB;
    
    start = clock();
    for (int i = 0; i < repeat; i++)
    {
        resultA = solvedByBrute(board, N, M);
    }
    finish = clock();
    double duration_brute = (double)(finish - start);

    start = clock();
    for (int i = 0; i < repeat; i++)
    {
        resultB = solvedByIntegral(board, N, M);
    }
    finish = clock();
    double duration_integral = (double)(finish - start);
    
    if (resultA != resultB)
        printf("Invalid value(two values is not equals), brute = %d, integral = %d\n", resultA, resultB);
    else
        printf("elapsed time: %dms(brute force), %dms(integral image)\n", (int)duration_brute, (int)duration_integral);
}