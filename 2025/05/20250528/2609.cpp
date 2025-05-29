#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b > a)
        swap(a, b);
    
    
    while (b >= 1)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n, m;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int gcdNum = gcd(n, m);
    cout << gcdNum << "\n" << n * m / gcdNum;

    return 0;
}