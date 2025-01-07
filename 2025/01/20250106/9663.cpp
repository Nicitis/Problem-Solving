#include <cstdio>

using namespace std;

int queenBoard[15][15]; // 각 칸마다 몇 개의 queen에 의해 공격받는지 표시

// 아래 행에 대해서 공격 추가하기
void AddQueen(int n, int row, int col)
{
    // 대각선으로 추가
    for (int i = 1; i < n - row; i++)
    {
        if (col - i >= 0)
            queenBoard[row + i][col - i]++;
        if (col + i < n)
            queenBoard[row + i][col + i]++;
    }

    // 아래로 추가
    for (int i = row + 1; i < n; i++)
    {
        queenBoard[i][col]++;
    }
}

// 아래 행에 대해 공격 제거하기
void RemoveQueen(int n, int row, int col)
{
    // 대각선으로 제거
    for (int i = 1; i < n - row; i++)
    {
        if (col - i >= 0)
            queenBoard[row + i][col - i]--;
        if (col + i < n)
            queenBoard[row + i][col + i]--;
    }

    // 아래로 제거
    for (int i = row + 1; i < n; i++)
    {
        queenBoard[i][col]--;
    }
}

// 백트래킹 방식으로 가능한 방법 탐색
long long NumberOfNQueen(int n, int row)
{
    if (row >= n)
        return 1LL;

    long long result = 0;
    for (int col = 0; col < n; col++)
    {
        // 공격받을 경우 제외
        if (queenBoard[row][col] > 0)
            continue;

        AddQueen(n, row, col);
        result += NumberOfNQueen(n, row + 1);
        RemoveQueen(n, row, col);
    }
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%lld\n", NumberOfNQueen(N, 0));

    return 0;
}