#include <cstdio>
#include <queue>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    
    std::queue<int> q;

    // insert
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    printf("<");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K - 1; j++)
        {
            q.push(q.front());
            q.pop();
        }
        if (i != 0)
            printf(", ");
        printf("%d", q.front());
        q.pop();
    }
    printf(">\n");

    return 0;
}