#include <iostream>

#define MAXIMUM 1000000000

using namespace std;

int modInverse(int a, int m)
{
    int old_x = 1;
    int x = 0;
    int m0 = m;
    int q, r, t;

    while (m != 0)
    {
        q = a / m;
        r = a % m;
        
        a = m;
        m = r;
        
        t = x;
        x = old_x - q * x;
        old_x = t;
        // cout << "a, m ->" << a << ", " << m <<
            // "/ old_x, x = " << old_x << ", " << x << "\n";
    }

    // 두 수가 서로소일 때만 역원 반환
    if (a != 1)
        return -1;

    while (old_x < 0)
        old_x += m0;
    
    // cout << a0 << " * " << old_x << " = " << a0 * old_x << " mod " 
        // << m0 << " = " << (a0 * old_x) % m0 << " = 1?\n";
    return old_x;
}

int main()
{
    int p[3], x[3];
    long long n, ansX;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p[0] >> p[1] >> p[2] >> x[0] >> x[1] >> x[2];

    n = p[0] * p[1] * p[2];

    if (x[0] == x[1] && x[1] == x[2])
    {
        cout << x[0];
        return 0;
    }

    ansX = 0;
    for (int i = 0; i < 3; i++)
    {
        // 1. ni = n / pi
        // 2. yi는 pi에 대한 ni의 모듈러 역원
        // 즉, (ni * yi) mod pi = 1
        // 3. x = sum(x_i * ni * yi)
        int ni = n / p[i];
        int yi = modInverse(ni, p[i]);
        // cout << p[i] << "에 대한 ni(" << ni << ")의 역원은 " << yi << "\n";
        if (yi == -1)
        {
            cout << "-1";
            return 0;
        }
        // cout << "ansX += " << x[i] << " * " << ni << " * " << yi 
            // << " = " << x[i] * ni * yi << "\n";
        ansX += x[i] * ni * yi;
    }

    cout << ansX % n;

    return 0;
}