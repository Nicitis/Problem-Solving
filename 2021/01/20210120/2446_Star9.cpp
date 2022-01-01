// 백준 2446 별 찍기 - 9 (https://www.acmicpc.net/problem/2446)
#include <cstdio>

int main()
{
    int n, k = 1;
    scanf("%d", &n);
    for (int i = 1; i > 0; i += k)
    {
        for (int j = 0; j < i - 1; j++)
            printf(" ");
        for (int j = i; j <= n; j++)
            printf("*");
        for (int j = i; j < n; j++)
            printf("*");
        printf("\n");
        if (i == n)
            k *= -1;
    }
    return 0;
}