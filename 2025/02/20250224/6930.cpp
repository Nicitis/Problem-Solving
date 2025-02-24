#include <iostream>

using namespace std;

int main()
{
    int x, m;
    cin >> x >> m;

    for (int n = 1; n < m; n++)
    {
        if ((x * n - 1) % m == 0)
        {
            cout << n << '\n';
            return 0;
        }
    }
    cout << "No such integer exists.\n";

    return 0;
}