#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << ((n != 4 && n != 7) ?
        ((n - 1) / 5 + ((n-1) % 5) % 2 + 1) : -1);

    return 0;
}