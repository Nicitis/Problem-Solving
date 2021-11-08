#include <cstdio>

// 재귀함수(순환함수)를 사용하지 않는 지수 제곱 함수
long long Pow(long long x, long long n)
{
    long long result = 1;
    long long multiply = x;
    while (n > 0)
    {
        if (n % 2 == 1)
            result *= multiply;
        multiply *= multiply;
        n >>= 1;
    }
    return result;
}

long long PowRecursive(long long x, long long n)
{
    if (n == 1)
        return x;
    long long result = PowRecursive(x, n / 2);
    result *= result;
    if (n % 2 == 1)
        result *= x;
    return result;
}

long long PowMod(long long x, long long n, long long m)
{
    long long result = 1;
    long long multiply = x;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            // result = (result * multiply) % m;
            result *= multiply;
            result %= m;
        }
        // multiply = (multiply * multiply) % m;
        multiply *= multiply;
        multiply %= m;
        n >>= 1;
    }
    return result;
}

// 페르마의 소정리를 통한 역원 구하기 복습: a의 역원은 a^(m-2) mod m
long long ModuloInverse(long long n, long long m)
{
    return PowMod(n, m - 2, m);
}

int main()
{
    long long y = 4;
    long long m = 998244353;

    long long a, b;

    printf("inverse for %d: ", m);
    scanf("%d", &y);
    printf("\ninverse of %d for %d = %d\n", y, m, ModuloInverse(y, m));


    /*
    while(1)
    {
        scanf("%d %d", &a, &b);
        prlong longf("Recursive: %d\n", PowRecursive(a, b));
        prlong longf("Not Recursive: %d\n", Pow(a, b));
    }
    */

}