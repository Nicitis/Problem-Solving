#include <cstdio>

int is666(int n)
{
    while (n >= 666)
    {
        if (n % 1000 == 666)
            return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num = 666 - 1;
    int series = 0;
    do
    {
        num++;
        if (is666(num))
        {
            series++;
        }
    } while (series < N);
    printf("%d\n", num);
    return 0;
}