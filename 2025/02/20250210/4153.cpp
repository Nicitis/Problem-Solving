// https://www.acmicpc.net/problem/4153
#include <cstdio>

int main()
{
    int a, b, c;

    while (true)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        
        if (a * a + b * b == c * c ||
            b * b + c * c == a * a ||
            c * c + a * a == b * b)
            printf("right\n");
        else
            printf("wrong\n");
    }


    return 0;
}