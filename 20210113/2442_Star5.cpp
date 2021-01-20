// 백준 2442 별 찍기 - 5 (https://www.acmicpc.net/problem/2442)
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            putchar(' ');
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            putchar('*');
        }
        printf("\n");
    }
}