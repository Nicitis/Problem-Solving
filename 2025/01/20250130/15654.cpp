#include <cstdio>
#include <algorithm>

int N, M;
int arr[8], check[8], answer[8];

void Backtrack(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (check[i])
            continue;
        answer[idx] = arr[i];
        check[i] = true;
        Backtrack(idx + 1);
        check[i] = false;
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    std::sort(arr, arr + N);

    Backtrack(0);

    return 0;
}