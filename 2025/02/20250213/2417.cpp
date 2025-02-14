#include <cstdio>
#include <cmath>

int main()
{
    long long n;

    scanf("%lld", &n);

    long double ld_q = sqrtl(n);
    long long q = (long long)ceill(ld_q);

    printf("%lld", q);

    return 0;
}