// 백준 10992 별 찍기 - 17 (https://www.acmicpc.net/problem/10992)
#include <cstdio>

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
            printf(" ");
        printf("*");
        for (j = 0; j < 2 * i - 3; j++)
            printf(i == n ? "*" : " ");
        printf(i == 1 ? "" : "*");
        printf("\n");
    }
}