// 백준 2441 별 찍기 - 4 (https://www.acmicpc.net/problem/2441)
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            putchar(' ');
        }
        for (int j = n; j > i; j--)
        {
            putchar('*');
        }
        puts("");
    }
}