// 백준 2445 별 찍기 - 8 (https://www.acmicpc.net/problem/2445)
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            printf("*");
        for (int j = 0; j < 2 * (n - i); j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            printf("*");
        for (int j = 0; j < 2 * (n - i); j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}