# 9663번-N-Queen

## 문제

- 백준, 골드4, [9663번: N-Queen](https://www.acmicpc.net/problem/9663)
- 풀이 날짜: 2025.1.6.
- 풀이 시간: 19:02~19:40(38분)
- 알고리즘 분류: 브루트포스, 백트래킹
- 사용 언어: C++

## 문제 해설

### 제약 조건 분석

해당 문제는 퀸의 특성을 고려하여 N x N 크기의 체스보드 위에 퀸이 서로 공격 불가능하도록 배치해야 한다.

이때 고려해야 할 점은, 무작정 모든 칸에 배치를 시도해보면 시간 복잡도가 과도하게 커질 수 있다는 것이다. 문제 자체가 탐색할 공간이 많기 때문에 최대한 같은 시간복잡도 내에서도 잘 탐색해야 한다.

각 행, 각 열마다 최대 하나의 퀸을 배치할 수 있기 때문에, 풀이 방법으로 각 행마다 돌아가며 퀸을 배치하는 방법을 선택하였다.

시간 복잡도를 계산해보면 각 행마다 N개 열에 퀸을 배치를 시도해보아야 하며, 이를 N개 행에 대해 반복해야 한다. 만약 조건 없이 모두 탐색하면 시간 복잡도는 ~$O(N^N)$를 따르고, N=14를 가정하면 14^14 = 11,112,006,825,558,016 = 약 1경 번의 연산을 요구한다. 절대 시간 제한인 10초 내로 끝낼 수 있는 문제가 아니므로, 조건에 맞지 않는 경우의 수는 아예 제외해야 한다.

이 점을 고려하면 해당 문제는 브루트포스보다 백트래킹 문제로 볼 수 있다. 조건에 맞지 않으면 끝까지 탐색하는 대신 이전 상태로 다시 돌아오도록 해야 한다.

### 문제 접근 방법

퀸은 대각선에 있거나 같은 행 또는 같은 열에 있는 모든 칸을 공격할 수 있다.

퀸을 서로 공격할 수 없게 배치해야 하므로 각 행마다 퀸을 배치할 때, 위 조건에 맞는 칸은 배제해야 한다.

따라서, 각 칸마다 몇 개의 퀸에 의해 공격받는지를 배열의 형태로 세도록 하였다.

백트래킹으로 다시 복구할 수 있어야 하므로 퀸을 하나 올릴 때마다 공격하는 모든 칸을 순회하며 각 칸별 퀸 카운트를 증가시킨다(AddQueen 함수).

반대로 모두 검사가 끝나 퀸을 해당 칸에서 제거할 땐 공격하는 모든 칸의 퀸 카운트를 감소시킨다(RemoveQueen 함수).

검사할 땐 자기가 배치할 칸이 다른 퀸에 의해 공격받아 퀸 카운트가 0보다 클 경우 더이상 조사하지 않는다.

### 코드

이를 고려하여 전체를 구현하면 이렇다.

배열 queenBoard로 각 칸별 퀸 카운트를 측정하도록 하였고, NumberOfNQueen 함수로 정답을 계산한다.

long long으로는 계산할 필요가 없었는데, 혹시나 범위를 초과할 수도 있어 자료형을 큰 값으로 설정했다.

```cpp
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
```

## 개선된 방법들

다른 사람의 풀이를 보다가 비트 연산자를 이용하는 방법도 발견했으나… 도무지 이해할 수 없어 넘겼다.

또다른 방법으로 2차원 배열로 다른 퀸에 의해 공격받는지를 검사하는 대신, 각 행별로 어느 열에 놓았는지를 저장하는 1차원 배열을 사용할 수도 있다.

그렇게 하면 각 행마다 퀸을 놓을 때마다 1차원 배열을 순회하여 (1) 같은 열에 놓았는지 (2) 대각선에 있는지(column 차이의 절댓값과 row 차이의 절댓값이 같으면 대각선임) 검사하는 방법도 있다.
