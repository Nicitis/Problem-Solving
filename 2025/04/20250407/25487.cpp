#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, a, b, c;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;

        cout << min({a, b, c}) << '\n';
    }

    return 0;
}