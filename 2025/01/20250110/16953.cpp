#include <cstdio>

int main()
{
    int A, B, op = 1;

    scanf("%d %d", &A, &B);

    while (B > A)
    {
        if (B % 10 == 1)
            B /= 10;
        else if (B % 2 == 0)
            B = B >> 1;
        else
            break;
        op++;
    }
    if (A != B)
        printf("-1\n");
    else
        printf("%d\n", op);

    return 0;
}