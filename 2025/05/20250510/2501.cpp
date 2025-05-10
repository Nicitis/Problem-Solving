#include <iostream>

using namespace std;

int main()
{
    int n, k;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (--k == 0)
            {
                cout << i;
                return 0;
            }
        }
    }

    cout << "0";

    return 0;
}