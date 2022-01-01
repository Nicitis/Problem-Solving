#include <iostream>
#include <algorithm>

int matrix[10][10];

int compareAsc(const void* a, const void* b)
{
    int ia = *(int*)a;
    int ib = *(int*)b;
    if (ia < ib)
        return -1;
    if (ia > ib)
        return 1;
    return 0;
}

int dfs( int row, int col, int N)
{
    // 현재 영역의 값을 0으로 한다.
    int current_area = 1;
    matrix[row][col] = 0;

    // 상하좌우로 값이 1인 구역이 있으면 탐색한다.
    if (row > 0 && matrix[row-1][col]) // 상
        current_area += dfs(row - 1, col, N);
    if (row < N - 1 && matrix[row+1][col]) // 하
        current_area += dfs(row + 1, col, N);
    if (col > 0 && matrix[row][col-1]) // 좌
        current_area += dfs(row, col - 1, N);
    if (col < N - 1 && matrix[row][col+1]) // 우
        current_area += dfs(row, col + 1, N);

    // 영역의 크기(주변 영역의 크기 + 1)를 반환한다
    return current_area;
}

int main()
{
    int count = 0;
    int N;
    int area[50];

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cin >> matrix[i][j];
        std::cin.ignore();
    }
    
    // 모든 점을 탐색
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 1을 발견하면 영역을 순회하며 크기를 검사한다.
            if (matrix[i][j])
            {
                area[count++] = dfs(i, j, N);
            }
        }
    }

    qsort(area, (size_t)count, sizeof(int), compareAsc);

    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << area[i];
        if (i + 1 == count)
            std::cout << std::endl;
        else
            std::cout << " ";
    }

    return 0;
}