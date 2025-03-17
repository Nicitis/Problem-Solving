#include <iostream>
#include <bitset> 
#define MOD 1000000007

using namespace std;

int main()
{
    long long n;
    long long bit = 1LL << 62;

    cin >> n;

    while ((bit & n) == 0)
    {
        bit >>= 1;
    }

    long long fib = 1LL, fib_prev = 0LL;

    while (bit > 1)
    {
        bit >>= 1;
        // 2 times
        long long double_fib = fib * (fib + 2 * fib_prev);
        long long double_fib_prev = fib * fib + fib_prev * fib_prev;
        double_fib %= MOD;
        double_fib_prev %= MOD;
        
        if (bit & n)
        {
            fib = (double_fib + double_fib_prev) % MOD;
            fib_prev = double_fib;
        }
        else
        {
            fib = double_fib;
            fib_prev = double_fib_prev;
        }
    }

    cout << fib << '\n';

    return 0;
}