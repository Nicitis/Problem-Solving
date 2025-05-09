#include <iostream>

using namespace std;

int main()
{
    int x, n = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x;

    while (x)
    {
        if ((x & 0x1) == 1)
            n++;
        x >>= 1;
    }

    cout << n;

    return 0;
}