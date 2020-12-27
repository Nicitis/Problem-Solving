#include <iostream>

// Backjoon 11401 "이항계수 3", https://www.acmicpc.net/problem/11401
// 출처: https://www.acmicpc.net/blog/view/29
// 페르마의 소정리를 이용하여 구하는 방법
long long mul(long long x, long long y, long long m)
{
    long long result = 1;
    while (y > 0)
    {
        if (y % 2 != 0)
        {
            result *= x;
            result %= m;
        }
        x *= x;
        x %= m;
        y /= 2;
    }
    return result;
}

int main()
{
    // A = N!, B = r!(N-r)!, C = 1,000,000,007
    // A/B mod C = A * B^(C-1) mod C
    long long m = 1000000007LL;
    long long result, n, r;
    long long a = 1, b = 1;

    std::cin >> n >> r;
    
    for (long long i = 1; i <= n; i++) // N!
    {
        a *= i;
        a %= m;
    }

    for (long long i = 1; i <= r; i++) // r!(N-r)!
    {
        b *= i;
        b %= m;
    }

    for (long long i = 1; i <= n-r; i++)
    {
        b *= i;
        b %= m;
    }

    b = mul(b, m - 2, m);
    result = a;
    result *= b;
    result %= m;

    std::cout << result;

    return 0;
}