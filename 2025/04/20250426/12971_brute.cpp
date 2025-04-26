#include <iostream>

using namespace std;

int main()
{
    int p[3], x[3];
    long long n, ansX = -1;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p[0] >> p[1] >> p[2] >> x[0] >> x[1] >> x[2];

    n = p[0] * p[1] * p[2];
    
    for (int i = 1; i < n; i++)
    {
        if (i % p[0] == x[0] &&
            i % p[1] == x[1] &&
            i % p[2] == x[2])
        {
            ansX = i;
            break;
        }
    }

    cout << ansX;

    return 0;
}