#include <cstdio>

int main()
{
    int live[1000], N, K;
    
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        live[i] = 1;
    }

    int count = 0;
    int idx = 0;
    printf("<");
    for (int i = 0; i < N; i++)
    {
        count = K - 1;
        while (count > 0)
        {
            if (live[idx % N] == 1)
            {
                count--;
            }
            idx++;
        }
        // live가 아닐 경우 넘기기
        while (live[idx % N] == 0)
            idx++;
        if (i > 0)
            printf(", ");
        printf("%d", (idx % N) + 1);
        live[idx % N] = 0;
    }
    printf(">\n");

    return 0;
}