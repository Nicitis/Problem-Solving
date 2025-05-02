#include <iostream>

using namespace std;

int main()
{
    int n, t, c, p;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t >> c >> p;

    cout << (((n - 1) / t) * c * p);

    return 0;
}