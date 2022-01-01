// 백준 2440 별 찍기 - 3 (https://www.acmicpc.net/problem/2440)
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}