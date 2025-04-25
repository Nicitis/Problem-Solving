#include <iostream>

using namespace std;

/*
덧셈 역원: (a + b) % n = 0
b = n - a

곱셈 역원: (a * c) % n = 1
c는 a의 역원으로 확장된 유클리드 알고리즘으로 해결한다.
*/

long long modInverse(long long a, long long n)
{
    long long t;
    long long x = 1;
    long long y = 0;
    long long n0 = n;

    while (n != 0)
    {
        long long q = a / n, r = a % n;

        a = n; n = r;

        t = y;
        y = x - q * y;
        x = t;
    }

    while (x < 0)
    {
        x += n0;
    }

    if (a != 1)
        return -1;
    else
        return x;
}

int main()
{
    long long n, a, b, c;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> a;

    b = n - a;
    c = modInverse(a, n);

    cout << b << " " << c;

    return 0;
}