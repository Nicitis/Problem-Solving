#include <iostream>

using namespace std;

int main()
{
    int t;

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> t;

    while (t--)
    {
        int n, pos = 0;
        cin >> n;
    
        while (n > 0)
        {
            if (n & 0x1)
                cout << pos << " ";
            n >>= 1;
            pos++;
        }
    }

    return 0;
}