#include <iostream>
#include <map>

#define MOD 1000000007
// #define MOD 10

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long n, f, c_a, c_b, k, mul_a, mul_b;
    long long prev_a, prev_b;
    cin >> n;

    int fibo[5] = { 0, 1, 1, 2, 3 };

    if (n <= 1)
    {
        cout << n << '\n';
        return 0;
    }

    c_a = 1;
    c_b = 1;
    mul_a = 1;
    mul_b = 1;
    k = 1;
    long long firstN = n;

    while(n - k - 1 > 2)
    {
        prev_a = c_a;
        prev_b = c_b;
        if (n - (k+k) - 2 >= 0)
        {
            // c_a = prev_a * prev_a + 2 * prev_a * prev_b;
            c_a = (mul_a + mul_b) * prev_a + mul_a * prev_b;
            c_a %= MOD;
            // c_b = prev_a * prev_a + prev_b * prev_b;
            c_b = mul_a * prev_a + mul_b * prev_b;
            c_b %= MOD;
            mul_a = c_a / prev_a;
            mul_b = c_b / prev_b;
            k = 2 * k + 1;
            cout << "1: f(" << firstN << ")=" << c_a << "f(" << n - k << ")+" 
                << c_b << "f(" << n - k - 1 << ")(k="<< k << ")\n";
        }
        else
        {
            n = n - k + 1;
            k = 3;
            c_a = 2 * prev_a + prev_b;
            c_a %= MOD;
            c_b = prev_a + prev_b;
            c_b %= MOD;
            mul_a = 3; cout << "... mul_a = " << c_a << "/" << prev_a << "=" << mul_a << '\n';
            mul_b = 2; cout << "... mul_b = " << c_b << "/" << prev_b << "=" << mul_b << '\n';
            cout << "2: f(" << firstN << ")=" << c_a << "f(" << n - k << ")+" 
                << c_b << "f(" << n - k - 1 << ")(k="<< k << ")\n";
        }
    }

    cout << "final: f(" << firstN << ")=" << c_a << "f(" << n - k << ")+" 
                << c_b << "f(" << n - k - 1 << ")(k="<< k << ")\n";
    f = (c_a * fibo[n-k]) % MOD + (c_b * fibo[n-k-1]) % MOD;
    f %= MOD;
    
    cout << f << '\n';

    return 0;
}