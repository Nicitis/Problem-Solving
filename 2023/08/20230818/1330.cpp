// 2023.08.18., 백준 1330 두 수 비교하기, https://www.acmicpc.net/problem/1330
#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a > b)
        printf(">");
    else if (a < b)
        printf("<");
    else
        printf("==");
        
    return 0;
}