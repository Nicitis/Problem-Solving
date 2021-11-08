// 백준 2438 별 찍기 - 1 (https://www.acmicpc.net/problem/2438)
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}