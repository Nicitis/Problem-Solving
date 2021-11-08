// 백준 10991 별 찍기 - 16 (https://www.acmicpc.net/problem/10991)
#include <cstdio>

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++) printf(" ");
        printf("*");
        for (j = 0; j < i; j++) printf(" *");
        printf("\n");
    }
}