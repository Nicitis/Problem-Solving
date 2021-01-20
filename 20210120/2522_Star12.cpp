// 백준 2522 별 찍기 - 12 (https://www.acmicpc.net/problem/2522)
#include <cstdio>

int main()
{
    int n;
    int k = 1;
    scanf("%d", &n);
    for (int i = 1; i > 0; i += k)
    {
        for (int j = 0; j < n - i; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
        if (i == n)
            k *= -1;
    }
    return 0;
}