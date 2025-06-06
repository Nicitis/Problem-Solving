#include <iostream>

using namespace std;

int main()
{
    int n, x, a, b;
    long long result = 0LL;
    const long long Divider = 1000000007LL;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;

    for (int i = 0; i <= n; i++)
    {
        cin >> a >> b;
        result = (result * x + a) % Divider;
    }

    cout << result;

    return 0;
}