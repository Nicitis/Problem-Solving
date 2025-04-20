#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n, a, b;

    cin >> x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x -= a * b;
    }

    cout << (x == 0 ? "Yes" : "No");

    return 0;
}