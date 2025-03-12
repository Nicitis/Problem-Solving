#include <cstdio>

int flowers[1001][1001];

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &flowers[i][0]);
    }
    for (int j = 1; j <= m; j++)
    {
        scanf("%d", &flowers[0][j]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            flowers[i][j] = 
                flowers[i-1][j] == flowers[i][j-1] ? 0 : 1;
        }
    }
    printf("%d\n", flowers[n][m]);

    return 0;
}