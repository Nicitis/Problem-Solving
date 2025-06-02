#include <iostream>

using namespace std;

int main()
{
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    int i = 1;
    int result;
    while (n > (i << 1))
    {
        i <<= 1;
    }
    cout << (n - i) * 2;

    return 0;
}